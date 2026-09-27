#include <fstream>   // For file handling
#include <iostream>  // For input and output
#include <string>    // For using string

int main() {

    // Open the source file for reading
    std::ifstream sourceFile("message.txt");

    // Create the destination file for writing
    std::ofstream destinationFile("message_copy.txt");

    // Check if the source file was opened successfully
    if (!sourceFile) {
        std::cerr << "Error: Could not open source file.\n";
        return 1;   // End the program if source file cannot be opened
    }

    // Check if the destination file was created successfully
    if (!destinationFile) {
        std::cerr << "Error: Could not create destination file.\n";
        return 1;   // End the program if destination file cannot be created
    }

    std::string line;   // Variable to store each line

    // Read the source file line by line
    while (std::getline(sourceFile, line)) {

        // Write each line into the destination file
        destinationFile << line << '\n';
    }

    // Display success message
    std::cout << "File copied successfully to message_copy.txt\n";

    return 0;   // End the program successfully
}
