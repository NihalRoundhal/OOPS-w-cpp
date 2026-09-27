#include <fstream>   // For file handling
#include <iostream>  // For input and output
#include <sstream>   // For reading data from a string
#include <string>    // For using string

int main() {

    // Open students.txt for reading
    std::ifstream inputFile("students.txt");

    // Check if the file was opened successfully
    if (!inputFile) {
        std::cerr << "Error: Could not open students.txt\n";
        return 1;   // End the program if file cannot be opened
    }

    int targetRollNumber;

    // Ask the user to enter the roll number to search
    std::cout << "Enter roll number to search: ";
    std::cin >> targetRollNumber;

    std::string line;       // Stores each line from the file
    bool found = false;     // Tracks whether the student is found

    // Read the file line by line
    while (std::getline(inputFile, line)) {

        // Convert the current line into a string stream
        std::stringstream record(line);

        // Variables to store student details
        std::string rollText;
        std::string name;
        std::string marksText;

        // Read roll number, name, and marks separated by '|'
        if (std::getline(record, rollText, '|') &&
            std::getline(record, name, '|') &&
            std::getline(record, marksText)) {

            // Convert roll number from string to integer
            int rollNumber = std::stoi(rollText);

            // Convert marks from string to double
            double marks = std::stod(marksText);

            // Check if the roll number matches the user's input
            if (rollNumber == targetRollNumber) {

                // Display the student record
                std::cout << "Record Found\n";
                std::cout << "Roll Number: " << rollNumber << '\n';
                std::cout << "Name: " << name << '\n';
                std::cout << "Marks: " << marks << '\n';

                found = true;  // Mark the record as found
                break;          // Stop searching
            }
        }
    }

    // If no matching student was found
    if (!found) {
        std::cout << "Student record not found.\n";
    }

    return 0;   // End the program successfully
}
