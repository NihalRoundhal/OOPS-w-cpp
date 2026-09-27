#include <cstring>     // For strncpy()
#include <fstream>     // For file handling
#include <iostream>    // For input and output

// Structure to store student details
struct StudentRecord {
    int rollNumber;    // Stores student's roll number
    char name[30];     // Stores student's name
    float marks;       // Stores student's marks
};

int main() {

    // Create a StudentRecord object and initialize all values to zero
    StudentRecord student{};

    // Assign roll number
    student.rollNumber = 101;

    // Copy student name into the character array
    std::strncpy(student.name, "Amit Patil",
                 sizeof(student.name) - 1);

    // Assign marks
    student.marks = 85.5F;

    {
        // Open students.dat in binary writing mode
        std::ofstream outputFile("students.dat", std::ios::binary);

        // Check whether the file was created successfully
        if (!outputFile) {
            std::cerr << "Error: Could not create students.dat\n";
            return 1;
        }

        // Write the complete StudentRecord object to the binary file
        outputFile.write(
            reinterpret_cast<const char*>(&student),
            sizeof(student)
        );
    }

    // Create another StudentRecord object to store the data read from file
    StudentRecord readStudent{};

    {
        // Open students.dat in binary reading mode
        std::ifstream inputFile("students.dat", std::ios::binary);

        // Check whether the file opened successfully
        if (!inputFile) {
            std::cerr << "Error: Could not open students.dat\n";
            return 1;
        }

        // Read the student record from the binary file
        inputFile.read(
            reinterpret_cast<char*>(&readStudent),
            sizeof(readStudent)
        );

        // Check whether the record was read successfully
        if (!inputFile) {
            std::cerr << "Error: Could not read record from students.dat\n";
            return 1;
        }
    }

    // Display the data read from the binary file
    std::cout << "Roll Number: "
              << readStudent.rollNumber << '\n';

    std::cout << "Name: "
              << readStudent.name << '\n';

    std::cout << "Marks: "
              << readStudent.marks << '\n';

    return 0;   // End the program successfully
}
