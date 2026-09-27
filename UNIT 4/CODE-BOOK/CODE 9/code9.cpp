#include <cstdio>      // For remove() and rename()
#include <fstream>     // For file handling
#include <iostream>    // For input and output
#include <sstream>     // For string stream
#include <string>      // For string data type

int main() {

    // Open students.txt for reading
    std::ifstream inputFile("students.txt");

    // Create temporary file for storing updated records
    std::ofstream temporaryFile("students_temp.txt");

    // Check if both files opened successfully
    if (!inputFile || !temporaryFile) {
        std::cerr << "Error: Could not open file(s).\n";
        return 1;   // Stop the program if file opening fails
    }

    int targetRollNumber;     // Stores roll number to be updated
    double updatedMarks;      // Stores new marks

    // Ask the user for the roll number
    std::cout << "Enter roll number to update: ";
    std::cin >> targetRollNumber;

    // Ask the user for the new marks
    std::cout << "Enter updated marks: ";
    std::cin >> updatedMarks;

    std::string line;         // Stores one line from the file
    bool found = false;       // Checks whether the student is found

    // Read the file line by line
    while (std::getline(inputFile, line)) {

        // Create a string stream to split the current record
        std::stringstream record(line);

        std::string rollText;     // Stores roll number as text
        std::string name;         // Stores student name
        std::string marksText;    // Stores marks as text

        // Split the record using '|' as separator
        if (std::getline(record, rollText, '|') &&
            std::getline(record, name, '|') &&
            std::getline(record, marksText)) {

            // Convert roll number from string to integer
            int rollNumber = std::stoi(rollText);

            // Check if this is the roll number entered by the user
            if (rollNumber == targetRollNumber) {

                // Write the updated record into temporary file
                temporaryFile << rollNumber << '|'
                              << name << '|'
                              << updatedMarks << '\n';

                // Student record has been found
                found = true;

            } else {

                // Copy the unchanged record to temporary file
                temporaryFile << line << '\n';
            }
        }
    }

    // Close the input file
    inputFile.close();

    // Close the temporary file
    temporaryFile.close();

    // If student was not found
    if (!found) {

        // Delete the temporary file
        std::remove("students_temp.txt");

        // Display message
        std::cout << "Student record not found. No update performed.\n";

        return 0;
    }

    // Delete the original students.txt file
    if (std::remove("students.txt") != 0) {
        std::cerr << "Error: Could not remove old students.txt\n";
        return 1;
    }

    // Rename temporary file as students.txt
    if (std::rename("students_temp.txt", "students.txt") != 0) {
        std::cerr << "Error: Could not rename temporary file.\n";
        return 1;
    }

    // Display success message
    std::cout << "Student marks updated successfully.\n";

    return 0;   // End the program successfully
}
