#include <cctype>      // For character checking functions
#include <fstream>     // For file handling
#include <iostream>    // For input and output
#include <string>      // For string data type

// Function to check whether a character is a vowel
bool isVowel(char ch) {

    // Convert character to lowercase
    ch = static_cast<char>(
        std::tolower(static_cast<unsigned char>(ch))
    );

    // Return true if character is a, e, i, o, or u
    return ch == 'a' || ch == 'e' || ch == 'i' ||
           ch == 'o' || ch == 'u';
}

int main() {

    std::string fileName;

    // Ask the user to enter the file name
    std::cout << "Enter file name: ";
    std::getline(std::cin, fileName);

    // Open the entered file
    std::ifstream inputFile(fileName);

    // Check whether the file opened successfully
    if (!inputFile) {
        std::cerr << "Error: Could not open "
                  << fileName << '\n';
        return 1;
    }

    // Variables to store file statistics
    std::size_t lines = 0;        // Number of lines
    std::size_t words = 0;        // Number of words
    std::size_t characters = 0;   // Number of characters
    std::size_t vowels = 0;       // Number of vowels
    std::size_t digits = 0;       // Number of digits
    std::size_t spaces = 0;       // Number of spaces

    // Keeps track of whether we are currently inside a word
    bool insideWord = false;

    char ch;   // Stores one character at a time

    // Read the file character by character
    while (inputFile.get(ch)) {

        // Count every character
        ++characters;

        // Count newline characters as lines
        if (ch == '\n') {
            ++lines;
        }

        // Check whether the character is whitespace
        if (std::isspace(static_cast<unsigned char>(ch))) {

            // Count only normal spaces
            if (ch == ' ') {
                ++spaces;
            }

            // A whitespace character means the word has ended
            insideWord = false;

        } else if (!insideWord) {

            // Start of a new word
            ++words;

            // Mark that we are inside a word
            insideWord = true;
        }

        // Check whether the character is an alphabet
        // and also check whether it is a vowel
        if (std::isalpha(static_cast<unsigned char>(ch))
            && isVowel(ch)) {

            ++vowels;
        }

        // Check whether the character is a digit
        if (std::isdigit(static_cast<unsigned char>(ch))) {
            ++digits;
        }
    }

    // Handle the last line if the file does not
    // end with a newline character
    if (characters > 0) {

        // Clear the EOF flag
        inputFile.clear();

        // Move reading position to the last character
        inputFile.seekg(-1, std::ios::end);

        char lastCharacter;

        // Read the last character
        inputFile.get(lastCharacter);

        // If the last character is not newline,
        // count it as the final line
        if (lastCharacter != '\n') {
            ++lines;
        }
    }

    // Display file statistics
    std::cout << "\nFile Statistics\n";

    // Display number of lines
    std::cout << "Lines: " << lines << '\n';

    // Display number of words
    std::cout << "Words: " << words << '\n';

    // Display number of characters
    std::cout << "Characters: " << characters << '\n';

    // Display number of vowels
    std::cout << "Vowels: " << vowels << '\n';

    // Display number of digits
    std::cout << "Digits: " << digits << '\n';

    // Display number of spaces
    std::cout << "Spaces: " << spaces << '\n';

    return 0;   // End the program successfully
}
