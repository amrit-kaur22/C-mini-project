#include <iostream>
using namespace std;

// Define Book class
class Book {
    int bookID;
    string title;
    string author;

public:
    // Function to input book details
    void inputDetails() {
        cout << "\nEnter Book ID: ";
        cin >> bookID;
        cin.ignore(); // to avoid skipping getline
        cout << "Enter Title: ";
        getline(cin, title);
        cout << "Enter Author: ";
        getline(cin, author);
    }

    // Function to display book details
    void displayDetails() {
        cout << "\nBook ID: " << bookID;
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author << endl;
    }

    // Function to get Book ID (for search)
    int getBookID() {
        return bookID;
    }

    // Optional: get title for search by title
    string getTitle() {
        return title;
    }
};

int main() {
    const int MAX_BOOKS = 100;
    Book library[MAX_BOOKS];
    int bookCount = 0;
    int choice;

    do {
        cout << "\n--- Library Management System ---\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book by ID\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (bookCount < MAX_BOOKS) {
                    library[bookCount].inputDetails();
                    bookCount++;
                    cout << "Book added successfully!\n";
                } else {
                    cout << "Library is full!\n";
                }
                break;

            case 2:
                if (bookCount == 0) {
                    cout << "No books in the library.\n";
                } else {
                    for (int i = 0; i < bookCount; i++) {
                        library[i].displayDetails();
                    }
                }
                break;

            case 3: {
                int searchID;
                bool found = false;
                cout << "Enter Book ID to search: ";
                cin >> searchID;

                for (int i = 0; i < bookCount; i++) {
                    if (library[i].getBookID() == searchID) {
                        cout << "Book Found:\n";
                        library[i].displayDetails();
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Book not found.\n";
                }
                break;
            }

            case 4:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}

