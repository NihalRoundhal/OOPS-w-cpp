#include <cstring>     // For strncpy()
#include <fstream>     // For file handling
#include <iostream>    // For input and output

// Structure to store student information
struct StudentRecord {
    int rollNumber;    // Stores roll number
    char name[30];     // Stores student name
    float marks;       // Stores marks
};

// Function to add one student record to the file
void addRecord(std::ofstream& file, int rollNumber,
               const char* name, float marks) {

    // Create a StudentRecord object
    StudentRecord student{};

    // Store roll number
    student.rollNumber = rollNumber;

    // Copy name into the character array
    std::strncpy(student.name, name, sizeof(student.name) - 1);

    // Store marks
    student.marks = marks;

    // Write the complete student record into the binary file
    file.write(
        reinterpret_cast<const char*>(&student),
        sizeof(student)
    );
}

int main() {

    {
        // Open records.dat in binary writing mode
        // ios::trunc clears old file contents
        std::ofstream outputFile(
            "records.dat",
            std::ios::binary | std::ios::trunc
        );

        // Check whether the file opened successfully
        if (!outputFile) {
            std::cerr << "Error: Could not create records.dat\n";
            return 1;
        }

        // Add first student record
        addRecord(outputFile, 101, "Amit", 85.5F);

        // Add second student record
        addRecord(outputFile, 102, "Neha", 91.0F);

        // Add third student record
        addRecord(outputFile, 103, "Ravi", 78.0F);
    }

    // Open the file in binary reading mode
    std::ifstream inputFile("records.dat", std::ios::binary);

    // Check whether the file opened successfully
    if (!inputFile) {
        std::cerr << "Error: Could not open records.dat\n";
        return 1;
    }

    int recordNumber;

    // Ask the user which record to read
    std::cout << "Enter record number to read (1 to 3): ";
    std::cin >> recordNumber;

    // Check whether the entered record number is valid
    if (recordNumber < 1 || recordNumber > 3) {
        std::cerr << "Invalid record number.\n";
        return 1;
    }

    // Calculate the position of the required record
    const std::streamoff offset =
        static_cast<std::streamoff>(recordNumber - 1) *
        static_cast<std::streamoff>(sizeof(StudentRecord));

    // Move the file reading position to the required record
    inputFile.seekg(offset, std::ios::beg);

    // Create an object to store the selected record
    StudentRecord selectedStudent{};

    // Read the selected student record from the file
    inputFile.read(
        reinterpret_cast<char*>(&selectedStudent),
        sizeof(selectedStudent)
    );

    // Check whether the record was read successfully
    if (!inputFile) {
        std::cerr << "Error: Could not read selected record.\n";
        return 1;
    }

    // Display the selected student's details
    std::cout << "Roll Number: "
              << selectedStudent.rollNumber << '\n';

    std::cout << "Name: "
              << selectedStudent.name << '\n';

    std::cout << "Marks: "
              << selectedStudent.marks << '\n';

    return 0;   // End the program successfully
}
