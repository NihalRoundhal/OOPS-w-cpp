#include <fstream>     // For file handling
#include <iostream>    // For input and output
#include <limits>      // For numeric_limits
#include <sstream>     // For string stream
#include <string>      // For string operations

// Class to represent a book
class Book {

private:
    int bookId;          // Stores book ID
    std::string title;   // Stores book title
    std::string author;  // Stores author name
    bool issued;         // Stores book status

public:

    // Constructor to initialize book details
    Book(int id, std::string bookTitle, std::string bookAuthor,
         bool issueStatus = false)
        : bookId(id),
          title(std::move(bookTitle)),
          author(std::move(bookAuthor)),
          issued(issueStatus) {}

    // Getter function to return book ID
    int getBookId() const {
        return bookId;
    }

    // Convert book details into a single string for file storage
    std::string toFileRecord() const {
        return std::to_string(bookId) + "|" +
               title + "|" +
               author + "|" +
               (issued ? "1" : "0");
    }

    // Display book details
    void display() const {
        std::cout << "Book ID: " << bookId << '\n';
        std::cout << "Title: " << title << '\n';
        std::cout << "Author: " << author << '\n';

        // Display Issued if true, otherwise Available
        std::cout << "Status: "
                  << (issued ? "Issued" : "Available")
                  << '\n';
    }
};


// Function to add a new book
void addBook() {

    int id;               // Stores book ID
    std::string title;    // Stores book title
    std::string author;   // Stores author name

    // Ask user for book ID
    std::cout << "Enter book ID: ";
    std::cin >> id;

    // Clear the newline from input buffer
    std::cin.ignore(
        std::numeric_limits<std::streamsize>::max(),
        '\n'
    );

    // Ask user for book title
    std::cout << "Enter title: ";
    std::getline(std::cin, title);

    // Ask user for author name
    std::cout << "Enter author: ";
    std::getline(std::cin, author);

    // Create a Book object
    Book book(id, title, author);

    // Open file in append mode
    std::ofstream outputFile(
        "library_books.txt",
        std::ios::app
    );

    // Check whether the file opened successfully
    if (!outputFile) {
        std::cerr << "Error: Could not open library_books.txt\n";
        return;
    }

    // Save book details to the file
    outputFile << book.toFileRecord() << '\n';

    // Display success message
    std::cout << "Book added successfully.\n";
}


// Function to display all books
void displayBooks() {

    // Open the library file for reading
    std::ifstream inputFile("library_books.txt");

    // Check whether the file exists
    if (!inputFile) {
        std::cout << "No library record file found.\n";
        return;
    }

    std::string line;   // Stores one line from the file

    // Read the file line by line
    while (std::getline(inputFile, line)) {

        // Create a string stream for the current record
        std::stringstream record(line);

        std::string idText;
        std::string title;
        std::string author;
        std::string issuedText;

        // Separate the record using | separator
        if (std::getline(record, idText, '|') &&
            std::getline(record, title, '|') &&
            std::getline(record, author, '|') &&
            std::getline(record, issuedText)) {

            // Convert ID from string to integer
            // Convert "1" to true and "0" to false
            Book book(
                std::stoi(idText),
                title,
                author,
                issuedText == "1"
            );

            // Display book details
            book.display();

            // Display separator
            std::cout << "-------------------------\n";
        }
    }
}


int main() {

    int choice;   // Stores menu choice

    // Continue until user chooses Exit
    do {

        // Display menu
        std::cout << "\nLibrary Record System\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. Display Books\n";
        std::cout << "0. Exit\n";

        // Ask user for choice
        std::cout << "Enter choice: ";
        std::cin >> choice;

        // Perform operation based on choice
        switch (choice) {

            case 1:
                // Add a new book
                addBook();
                break;

            case 2:
                // Display all books
                displayBooks();
                break;

            case 0:
                // Exit the program
                std::cout << "Exiting program.\n";
                break;

            default:
                // Handle invalid choice
                std::cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;   // End the program successfully
}
