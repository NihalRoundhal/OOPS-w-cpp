#include <cstdio>      // For remove() and rename()
#include <fstream>     // For file handling
#include <iostream>    // For input and output
#include <limits>      // For numeric_limits
#include <sstream>     // For string stream
#include <string>      // For string data type

// Function to add a new student record
void addStudent() {

    // Open file in append mode so new records are added at the end
    std::ofstream outputFile(
        "student_records.txt",
        std::ios::app
    );

    // Check whether the file opened successfully
    if (!outputFile) {
        std::cerr << "Error: Could not open student_records.txt\n";
        return;
    }

    int rollNumber;      // Stores roll number
    std::string name;    // Stores student name
    double marks;        // Stores student marks

    // Take roll number from user
    std::cout << "Enter roll number: ";
    std::cin >> rollNumber;

    // Take student name from user
    std::cout << "Enter name: ";

    // Clear the newline left in the input buffer
    std::cin.ignore(
        std::numeric_limits<std::streamsize>::max(),
        '\n'
    );

    // Read complete name including spaces
    std::getline(std::cin, name);

    // Take marks from user
    std::cout << "Enter marks: ";
    std::cin >> marks;

    // Store record in file using | as separator
    outputFile << rollNumber << '|'
               << name << '|'
               << marks << '\n';

    std::cout << "Record added successfully.\n";
}


// Function to display all student records
void displayStudents() {

    // Open the student record file for reading
    std::ifstream inputFile("student_records.txt");

    // Check whether the file exists
    if (!inputFile) {
        std::cout << "No student record file found.\n";
        return;
    }

    std::string line;   // Stores one complete line

    // Display table heading
    std::cout << "\nRoll No.\tName\t\tMarks\n";
    std::cout << "----------------------------------------\n";

    // Read file line by line
    while (std::getline(inputFile, line)) {

        // Create string stream to separate the record
        std::stringstream record(line);

        std::string rollText;
        std::string name;
        std::string marksText;

        // Split the record using | separator
        if (std::getline(record, rollText, '|') &&
            std::getline(record, name, '|') &&
            std::getline(record, marksText)) {

            // Display the student record
            std::cout << rollText << "\t\t"
                      << name << "\t\t"
                      << marksText << '\n';
        }
    }
}


// Function to search for a student
void searchStudent() {

    // Open file for reading
    std::ifstream inputFile("student_records.txt");

    // Check whether the file exists
    if (!inputFile) {
        std::cout << "No student record file found.\n";
        return;
    }

    int targetRoll;

    // Ask user for roll number to search
    std::cout << "Enter roll number to search: ";
    std::cin >> targetRoll;

    std::string line;
    bool found = false;     // Stores whether student is found

    // Read file line by line
    while (std::getline(inputFile, line)) {

        // Create stream for current record
        std::stringstream record(line);

        std::string rollText;
        std::string name;
        std::string marksText;

        // Separate roll number, name and marks
        if (std::getline(record, rollText, '|') &&
            std::getline(record, name, '|') &&
            std::getline(record, marksText)) {

            // Convert roll number from string to integer
            if (std::stoi(rollText) == targetRoll) {

                // Display the found record
                std::cout << "Record Found\n";
                std::cout << "Roll Number: " << rollText << '\n';
                std::cout << "Name: " << name << '\n';
                std::cout << "Marks: " << marksText << '\n';

                // Mark record as found
                found = true;

                // Stop searching
                break;
            }
        }
    }

    // Display message if student was not found
    if (!found) {
        std::cout << "Student not found.\n";
    }
}


// Function to update student marks
void updateMarks() {

    // Open original file for reading
    std::ifstream inputFile("student_records.txt");

    // Create temporary file for updated records
    std::ofstream temporaryFile("student_records_temp.txt");

    // Check whether both files opened successfully
    if (!inputFile || !temporaryFile) {
        std::cerr << "Error: Could not open record file(s).\n";
        return;
    }

    int targetRoll;     // Roll number to update
    double newMarks;    // New marks

    // Ask user for roll number
    std::cout << "Enter roll number to update: ";
    std::cin >> targetRoll;

    // Ask user for new marks
    std::cout << "Enter new marks: ";
    std::cin >> newMarks;

    std::string line;
    bool found = false;

    // Read original file line by line
    while (std::getline(inputFile, line)) {

        // Create stream for current record
        std::stringstream record(line);

        std::string rollText;
        std::string name;
        std::string marksText;

        // Separate record fields
        if (std::getline(record, rollText, '|') &&
            std::getline(record, name, '|') &&
            std::getline(record, marksText)) {

            // Check whether roll number matches
            if (std::stoi(rollText) == targetRoll) {

                // Write updated marks to temporary file
                temporaryFile << rollText << '|'
                              << name << '|'
                              << newMarks << '\n';

                found = true;

            } else {

                // Copy unchanged record
                temporaryFile << line << '\n';
            }
        }
    }

    // Close both files
    inputFile.close();
    temporaryFile.close();

    // If student was not found
    if (!found) {

        // Delete temporary file
        std::remove("student_records_temp.txt");

        std::cout << "Student not found. No changes made.\n";
        return;
    }

    // Delete the old record file and rename temporary file
    if (std::remove("student_records.txt") != 0 ||
        std::rename(
            "student_records_temp.txt",
            "student_records.txt"
        ) != 0) {

        std::cerr << "Error: Could not replace the record file.\n";
        return;
    }

    // Display success message
    std::cout << "Marks updated successfully.\n";
}


int main() {

    int choice;     // Stores user's menu choice

    // Continue showing menu until user chooses 0
    do {

        // Display menu
        std::cout << "\nStudent Record Manager\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Display All Students\n";
        std::cout << "3. Search Student\n";
        std::cout << "4. Update Marks\n";
        std::cout << "0. Exit\n";

        // Ask user for choice
        std::cout << "Enter choice: ";
        std::cin >> choice;

        // Perform operation according to user's choice
        switch (choice) {

            case 1:
                // Add a student
                addStudent();
                break;

            case 2:
                // Display all students
                displayStudents();
                break;

            case 3:
                // Search for a student
                searchStudent();
                break;

            case 4:
                // Update student marks
                updateMarks();
                break;

            case 0:
                // Exit the program
                std::cout << "Exiting program.\n";
                break;

            default:
                // Handle invalid choice
                std::cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;   // End program successfully
}
