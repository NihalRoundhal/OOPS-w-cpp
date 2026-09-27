#include <fstream>   // For file handling
#include <iostream>  // For input and output
#include <string>    // For using string

int main() {

    // Open the file "message.txt" for reading
    std::ifstream inputFile("message.txt");

    // Check if the file was opened successfully
    if (!inputFile) {
        std::cerr << "Error: Could not open message.txt\n";
        return 1;   // End the program if file cannot be opened
    }

    std::string line;   // Variable to store each line from the file

    // Display heading
    std::cout << "File Content:\n";

    // Read the file line by line until the end
    while (std::getline(inputFile, line)) {
        // Display the current line
        std::cout << line << '\n';
    }

    // Close the file
    inputFile.close();

    return 0;   // End the program successfully
}
