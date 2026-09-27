#include <cctype>    // For checking spaces and characters
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

    // Variables to store the counts
    std::size_t lineCount = 0;        // Stores number of lines
    std::size_t wordCount = 0;        // Stores number of words
    std::size_t characterCount = 0;   // Stores number of characters

    bool insideWord = false;   // Tracks whether we are inside a word
    char ch;                   // Stores each character

    // Read the file character by character
    while (inputFile.get(ch)) {

        // Increase character count
        ++characterCount;

        // Count a line when a newline character is found
        if (ch == '\n') {
            ++lineCount;
        }

        // Check if the character is a space, tab, or newline
        if (std::isspace(static_cast<unsigned char>(ch))) {
            insideWord = false;
        }

        // If character is not a space and we are not already in a word
        else if (!insideWord) {
            ++wordCount;       // Increase word count
            insideWord = true; // Mark that we are inside a word
        }
    }

    // Check if the file contains any characters
    if (characterCount > 0) {

        // Clear the end-of-file flag
        inputFile.clear();

        // Move to the last character of the file
        inputFile.seekg(-1, std::ios::end);

        char lastCharacter;

        // Read the last character
        inputFile.get(lastCharacter);

        // If the last character is not a newline,
        // count the last line
        if (lastCharacter != '\n') {
            ++lineCount;
        }
    }

    // Display the total number of lines
    std::cout << "Lines: " << lineCount << '\n';

    // Display the total number of words
    std::cout << "Words: " << wordCount << '\n';

    // Display the total number of characters
    std::cout << "Characters: " << characterCount << '\n';

    return 0;   // End the program successfully
}
