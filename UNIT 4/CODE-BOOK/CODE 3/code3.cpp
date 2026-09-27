#include <fstream>   // For file handling
#include <iostream>  // For input and output

int main() {

    // Open "message.txt" in append mode
    // Append mode adds new data at the end of the file
    std::ofstream outputFile("message.txt", std::ios::app);

    // Check if the file was opened successfully
    if (!outputFile) {
        std::cerr << "Error: Could not open message.txt for appending\n";
        return 1;   // End the program if file cannot be opened
    }

    // Add a new line at the end of the file
    outputFile << "This line was added using append mode.\n";

    // Close the file
    outputFile.close();

    // Display success message
    std::cout << "New line appended successfully.\n";

    return 0;   // End the program successfully
}
