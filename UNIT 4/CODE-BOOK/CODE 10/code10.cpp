#include <fstream>     // For file handling
#include <iostream>    // For input and output
#include <string>      // For string operations

int main() {

    // Open navigation.txt for both reading and writing
    // ios::trunc clears the existing file contents
    std::fstream file("navigation.txt",
                      std::ios::in | std::ios::out | std::ios::trunc);

    // Check whether the file opened successfully
    if (!file) {
        std::cerr << "Error: Could not open navigation.txt\n";
        return 1;   // Stop the program
    }

    // Write ABCDE into the file
    file << "ABCDE";

    // Display the current output/write position
    std::cout << "Output position after writing: "
              << file.tellp() << '\n';

    // Make sure all written data is saved to the file
    file.flush();

    // Move the input/read position to the beginning
    file.seekg(0, std::ios::beg);

    char firstCharacter;

    // Read the first character from the file
    file.get(firstCharacter);

    // Display the first character
    std::cout << "First character: "
              << firstCharacter << '\n';

    // Display the current input/read position
    std::cout << "Input position after reading one character: "
              << file.tellg() << '\n';

    // Move the input position to position 2
    file.seekg(2, std::ios::beg);

    char thirdCharacter;

    // Read the character at position 2
    file.get(thirdCharacter);

    // Display the character at position 2
    std::cout << "Character at position 2: "
              << thirdCharacter << '\n';

    // Move the output/write position to position 5
    file.seekp(5, std::ios::beg);

    // Write F at position 5
    file << "F";

    // Close the file
    file.close();

    // Display completion message
    std::cout << "Navigation completed. Check navigation.txt\n";

    return 0;   // End the program successfully
}
