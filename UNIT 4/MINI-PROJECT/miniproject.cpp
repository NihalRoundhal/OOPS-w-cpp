#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// Structure to store book details
struct Book {
    string isbn;
    string title;
    string author;
    string category;
    string availability;
};

// Function to add a new book
void addBook() {
    Book b;

    cout << "\nEnter ISBN: ";
    cin >> b.isbn;
    cin.ignore();

    cout << "Enter Title: ";
    getline(cin, b.title);

    cout << "Enter Author: ";
    getline(cin, b.author);

    cout << "Enter Category: ";
    getline(cin, b.category);

    // New book is available by default
    b.availability = "Available";

    // Open file in append mode
    ofstream file("books.txt", ios::app);

    // Store book details separated by '|'
    file << b.isbn << "|"
         << b.title << "|"
         << b.author << "|"
         << b.category << "|"
         << b.availability << endl;

    file.close();

    cout << "\nBook added successfully!\n";
}

// Function to display a book
void displayBook(Book b) {
    cout << "\nISBN: " << b.isbn;
    cout << "\nTitle: " << b.title;
    cout << "\nAuthor: " << b.author;
    cout << "\nCategory: " << b.category;
    cout << "\nAvailability: " << b.availability << endl;
}

// Function to search a book by ISBN
void searchBook() {
    string isbn;
    cout << "\nEnter ISBN to search: ";
    cin >> isbn;

    ifstream file("books.txt");
    string line;
    bool found = false;

    // Read file line by line
    while (getline(file, line)) {
        stringstream ss(line);
        Book b;

        // Read each field separated by '|'
        getline(ss, b.isbn, '|');
        getline(ss, b.title, '|');
        getline(ss, b.author, '|');
        getline(ss, b.category, '|');
        getline(ss, b.availability, '|');

        if (b.isbn == isbn) {
            displayBook(b);
            found = true;
            break;
        }
    }

    file.close();

    if (!found)
        cout << "\nBook not found!\n";
}

// Function to issue a book
void issueBook() {
    string isbn;
    cout << "\nEnter ISBN to issue: ";
    cin >> isbn;

    ifstream file("books.txt");
    ofstream temp("temp.txt");

    string line;
    bool found = false;

    while (getline(file, line)) {
        stringstream ss(line);
        Book b;

        getline(ss, b.isbn, '|');
        getline(ss, b.title, '|');
        getline(ss, b.author, '|');
        getline(ss, b.category, '|');
        getline(ss, b.availability, '|');

        if (b.isbn == isbn) {
            found = true;

            if (b.availability == "Available") {
                b.availability = "Issued";
                cout << "\nBook issued successfully!\n";
            } else {
                cout << "\nBook is already issued!\n";
            }
        }

        // Write updated data into temporary file
        temp << b.isbn << "|"
             << b.title << "|"
             << b.author << "|"
             << b.category << "|"
             << b.availability << endl;
    }

    file.close();
    temp.close();

    // Replace original file with updated file
    remove("books.txt");
    rename("temp.txt", "books.txt");

    if (!found)
        cout << "\nBook not found!\n";
}

// Function to return a book
void returnBook() {
    string isbn;
    cout << "\nEnter ISBN to return: ";
    cin >> isbn;

    ifstream file("books.txt");
    ofstream temp("temp.txt");

    string line;
    bool found = false;

    while (getline(file, line)) {
        stringstream ss(line);
        Book b;

        getline(ss, b.isbn, '|');
        getline(ss, b.title, '|');
        getline(ss, b.author, '|');
        getline(ss, b.category, '|');
        getline(ss, b.availability, '|');

        if (b.isbn == isbn) {
            found = true;

            if (b.availability == "Issued") {
                b.availability = "Available";
                cout << "\nBook returned successfully!\n";
            } else {
                cout << "\nBook is already available!\n";
            }
        }

        temp << b.isbn << "|"
             << b.title << "|"
             << b.author << "|"
             << b.category << "|"
             << b.availability << endl;
    }

    file.close();
    temp.close();

    // Replace original file
    remove("books.txt");
    rename("temp.txt", "books.txt");

    if (!found)
        cout << "\nBook not found!\n";
}

// Function to update book details
void updateBook() {
    string isbn;
    cout << "\nEnter ISBN to update: ";
    cin >> isbn;
    cin.ignore();

    ifstream file("books.txt");
    ofstream temp("temp.txt");

    string line;
    bool found = false;

    while (getline(file, line)) {
        stringstream ss(line);
        Book b;

        getline(ss, b.isbn, '|');
        getline(ss, b.title, '|');
        getline(ss, b.author, '|');
        getline(ss, b.category, '|');
        getline(ss, b.availability, '|');

        if (b.isbn == isbn) {
            found = true;

            cout << "Enter new title: ";
            getline(cin, b.title);

            cout << "Enter new author: ";
            getline(cin, b.author);

            cout << "Enter new category: ";
            getline(cin, b.category);

            cout << "\nBook details updated successfully!\n";
        }

        temp << b.isbn << "|"
             << b.title << "|"
             << b.author << "|"
             << b.category << "|"
             << b.availability << endl;
    }

    file.close();
    temp.close();

    remove("books.txt");
    rename("temp.txt", "books.txt");

    if (!found)
        cout << "\nBook not found!\n";
}

// Function to generate availability report
void availabilityReport() {
    ifstream file("books.txt");
    string line;

    cout << "\n========== BOOK AVAILABILITY REPORT ==========\n";

    while (getline(file, line)) {
        stringstream ss(line);
        Book b;

        getline(ss, b.isbn, '|');
        getline(ss, b.title, '|');
        getline(ss, b.author, '|');
        getline(ss, b.category, '|');
        getline(ss, b.availability, '|');

        // Display only required availability information
        cout << "\nISBN: " << b.isbn;
        cout << "\nTitle: " << b.title;
        cout << "\nStatus: " << b.availability << endl;
    }

    file.close();
}

// Main function
int main() {
    int choice;

    do {
        cout << "\n\n===== LIBRARY BOOK MANAGEMENT =====";
        cout << "\n1. Add Book";
        cout << "\n2. Search Book";
        cout << "\n3. Issue Book";
        cout << "\n4. Return Book";
        cout << "\n5. Update Book";
        cout << "\n6. Availability Report";
        cout << "\n7. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;

            case 2:
                searchBook();
                break;

            case 3:
                issueBook();
                break;

            case 4:
                returnBook();
                break;

            case 5:
                updateBook();
                break;

            case 6:
                availabilityReport();
                break;

            case 7:
                cout << "\nProgram ended.\n";
                break;

            default:
                cout << "\nInvalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}
