#include <fstream>      // For file handling: ifstream and ofstream
#include <iostream>     // For input/output: cin, cout, cerr
#include <sstream>      // For stringstream
#include <string>       // For using string

using namespace std;

// Class Student represents student information
class Student {
private:
    int rollNo;         // Stores student roll number
    string name;        // Stores student name
    double marks;       // Stores student marks

public:
    // Default constructor
    Student() : rollNo(0), marks(0.0) {}

    // Parameterized constructor
    Student(int r, string n, double m)
        : rollNo(r), name(n), marks(m) {}

    // Function to save student data into a file
    void saveToFile(ofstream& out) const {
        // Write data in CSV format
        out << rollNo << ',' << name << ',' << marks << '\n';
    }

    // Function to read student data from one line
    bool loadFromLine(const string& line) {

        string rollText;    // Stores roll number as text
        string marksText;   // Stores marks as text

        // Create stringstream using the given line
        stringstream stream(line);

        // Read roll number until comma
        if (!getline(stream, rollText, ','))
            return false;

        // Read student name until comma
        if (!getline(stream, name, ','))
            return false;

        // Read marks until the end of the line
        if (!getline(stream, marksText))
            return false;

        // Convert roll number from string to integer
        rollNo = stoi(rollText);

        // Convert marks from string to double
        marks = stod(marksText);

        return true;    // Data loaded successfully
    }

    // Function to display student information
    void display() const {
        cout << "Roll: " << rollNo
             << " | Name: " << name
             << " | Marks: " << marks << endl;
    }
};

int main() {

    // Open students.csv file for writing
    ofstream outFile("students.csv");

    // Check whether the file opened successfully
    if (!outFile) {
        cerr << "Unable to open students.csv for writing." << endl;
        return 1;       // End program if file cannot be opened
    }

    // Create three Student objects
    Student s1(101, "Rahul Patil", 85.5);
    Student s2(102, "Priya Sharma", 92.0);
    Student s3(103, "Amit Kulkarni", 78.5);

    // Save student records into the CSV file
    s1.saveToFile(outFile);
    s2.saveToFile(outFile);
    s3.saveToFile(outFile);

    // Close the output file
    outFile.close();

    // Open students.csv file for reading
    ifstream inFile("students.csv");

    // Check whether the file opened successfully
    if (!inFile) {
        cerr << "Unable to open students.csv for reading." << endl;
        return 1;       // End program if file cannot be opened
    }

    // Display report heading
    cout << "=== Student Report ===" << endl;

    string line;        // Stores one line read from the file

    // Read the file line by line
    while (getline(inFile, line)) {

        // Create a temporary Student object
        Student student;

        // Load data from the current line
        if (student.loadFromLine(line)) {

            // Display the student information
            student.display();
        }
    }

    return 0;           // End the program successfully
}
