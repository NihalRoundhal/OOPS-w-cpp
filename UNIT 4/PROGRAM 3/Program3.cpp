#include <cstring>      // For C-style string functions
#include <fstream>      // For file handling
#include <iostream>     // For input and output

using namespace std;

// Structure to store image information
struct ImageMetadata {
    int width;           // Stores image width
    int height;          // Stores image height
    char format[10];     // Stores image format such as PNG or JPEG
};

int main() {

    // Create three image records
    ImageMetadata image1{1920, 1080, "PNG"};
    ImageMetadata image2{1280, 720, "JPEG"};
    ImageMetadata image3{3840, 2160, "PNG"};

    // Open binary file for writing
    ofstream output("images.bin", ios::binary);

    // Check if the file opened successfully
    if (!output) {
        cerr << "Unable to open binary file for writing." << endl;
        return 1;       // Stop the program if file cannot be opened
    }

    // Write image1 data into the binary file
    output.write(
        reinterpret_cast<const char*>(&image1),
        sizeof(ImageMetadata)
    );

    // Write image2 data into the binary file
    output.write(
        reinterpret_cast<const char*>(&image2),
        sizeof(ImageMetadata)
    );

    // Write image3 data into the binary file
    output.write(
        reinterpret_cast<const char*>(&image3),
        sizeof(ImageMetadata)
    );

    // Close the output file
    output.close();

    // Open the binary file for reading
    ifstream input("images.bin", ios::binary);

    // Check if the file opened successfully
    if (!input) {
        cerr << "Unable to open binary file for reading." << endl;
        return 1;       // Stop the program if file cannot be opened
    }

    // Create an empty object to store each record while reading
    ImageMetadata item{};

    // Used to display record numbers
    int recordNo = 1;

    // Display heading
    cout << "=== Image Metadata ===" << endl;

    // Read one complete ImageMetadata record at a time
    while (
        input.read(
            reinterpret_cast<char*>(&item),
            sizeof(ImageMetadata)
        )
    ) {

        // Display image information
        cout << "Record " << recordNo++ << ": "
             << item.width << " x " << item.height
             << " | " << item.format << endl;
    }

    return 0;       // End the program successfully
}
