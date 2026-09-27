#include <fstream>   // For file handling
#include <iostream>  // For input and output
#include <string>    // For using string

int main() {

    // Open the file for reading
    std::ifstream inputFile("message.txt");

    // Check if the file was opened successfully
    if (!inputFile) {
        std::cerr << "Error: Could not open message.txt\n";
        return 1;   // End the program if file cannot be opened
    }

    std::string searchWord;

    // Ask the user for the word to search
    std::cout << "Enter word to search: ";
    std::cin >> searchWord;

    std::string word;  // Stores each word read from the file
    int count = 0;     // Stores the number of occurrences

    // Read the file word by word
    while (inputFile >> word) {

        // Check if the current word matches the search word
        if (word == searchWord) {
            ++count;   // Increase the count
        }
    }

    // Display the number of times the word was found
    std::cout << "The word '" << searchWord
              << "' occurred " << count << " time(s).\n";

    return 0;   // End the program successfully
}
