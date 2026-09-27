#include <fstream>     // For file handling
#include <iostream>    // For input and output
#include <string>      // For string data type

int main() {

    // Open the file for reading
    std::ifstream inputFile("missing_file.txt");

    // Check whether the file was opened successfully
    if (!inputFile.is_open()) {

        // Display error message if file cannot be opened
        std::cerr << "Error: File could not be opened.\n";

        // Tell the user to check the file location
        std::cerr << "Check whether missing_file.txt exists in the current folder.\n";

        return 1;   // Stop the program
    }

    std::string line;   // Stores one line of the file

    // Read the file line by line
    while (std::getline(inputFile, line)) {

        // Display each line on the screen
        std::cout << line << '\n';
    }

    // Check if the end of the file was reached
    if (inputFile.eof()) {

        // File was completely read
        std::cout << "End of file reached normally.\n";

    // Check for a serious input/output error
    } else if (inputFile.bad()) {

        std::cerr << "A serious file I/O error occurred.\n";

    // Check for another logical reading error
    } else if (inputFile.fail()) {

        std::cerr << "A logical file read error occurred.\n";
    }

    return 0;   // End the program successfully
}
