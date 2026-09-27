#include <fstream>      // Used for file handling
#include <iostream>     // Used for input and output

int main() {

    // Create and open a file named "message.txt" for writing
    std::ofstream outputFile("message.txt");

    // Check if the file was created/opened successfully
    if (!outputFile) {
        std::cerr << "Error: Could not create message.txt\n";
        return 1;       // End the program if file creation fails
    }

    // Write the first line into the file
    outputFile << "Welcome to C++ File Handling\n";

    // Write the second line into the file
    outputFile << "This is the first line written to a file.\n";

    // Write the third line into the file
    outputFile << "Files store data permanently.\n";

    // Close the file after writing
    outputFile.close();

    // Display a success message on the screen
    std::cout << "Data written successfully to message.txt\n";

    return 0;           // End the program successfully
}
