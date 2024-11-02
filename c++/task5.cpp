#include <iostream>
#include <vector>
#include <string>
#include <ctime>

struct Book {
    std::string title;
    std::string author;
    std::string isbn;
    bool available;
};

struct Borrower {
    std::string name;
    std::string borrowedBookISBN;
    std::time_t dueDate;
};

class Library {
private:
    std::vector<Book> books;
    std::vector<Borrower> borrowers;

public:
    void addBook(const std::string& title, const std::string& author, const std::string& isbn) {
        books.push_back({title, author, isbn, true});
    }

    void searchBook(const std::string& query) {
        for (const auto& book : books) {
            if (book.title.find(query) != std::string::npos ||
                book.author.find(query) != std::string::npos ||
                book.isbn.find(query) != std::string::npos) {
                std::cout << "Found Book: " << book.title << ", Author: " << book.author 
                          << ", ISBN: " << book.isbn << (book.available ? " (Available)" : " (Checked Out)") << "\n";
            }
        }
    }

    void checkoutBook(const std::string& isbn, const std::string& borrowerName) {
        for (auto& book : books) {
            if (book.isbn == isbn && book.available) {
                book.available = false;
                borrowers.push_back({borrowerName, isbn, std::time(0) + 7 * 24 * 60 * 60}); // due in 7 days
                std::cout << "Book checked out successfully.\n";
                return;
            }
        }
        std::cout << "Book not available for checkout.\n";
    }

    void returnBook(const std::string& isbn) {
        for (auto& book : books) {
            if (book.isbn == isbn && !book.available) {
                book.available = true;
                for (auto it = borrowers.begin(); it != borrowers.end(); ++it) {
                    if (it->borrowedBookISBN == isbn) {
                        std::time_t now = std::time(0);
                        double daysOverdue = std::difftime(now, it->dueDate) / (60 * 60 * 24);
                        if (daysOverdue > 0) {
                            std::cout << "Book returned. Fine: $" << daysOverdue * 0.50 << "\n";
                        } else {
                            std::cout << "Book returned on time.\n";
                        }
                        borrowers.erase(it);
                        return;
                    }
                }
            }
        }
        std::cout << "Book was not checked out.\n";
    }
};

int main() {
    Library library;
    int choice;
    
    do {
        std::cout << "\nLibrary Management System:\n";
        std::cout << "1. Add Book\n2. Search Book\n3. Checkout Book\n4. Return Book\n5. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;
        std::cin.ignore(); // Clear newline from input buffer

        switch (choice) {
            case 1: {
                std::string title, author, isbn;
                std::cout << "Enter book title: ";
                std::getline(std::cin, title);
                std::cout << "Enter book author: ";
                std::getline(std::cin, author);
                std::cout << "Enter book ISBN: ";
                std::getline(std::cin, isbn);
                library.addBook(title, author, isbn);
                break;
            }
            case 2: {
                std::string query;
                std::cout << "Enter title, author, or ISBN to search: ";
                std::getline(std::cin, query);
                library.searchBook(query);
                break;
            }
            case 3: {
                std::string isbn, borrowerName;
                std::cout << "Enter ISBN of the book to checkout: ";
                std::getline(std::cin, isbn);
                std::cout << "Enter borrower's name: ";
                std::getline(std::cin, borrowerName);
                library.checkoutBook(isbn, borrowerName);
                break;
            }
            case 4: {
                std::string isbn;
                std::cout << "Enter ISBN of the book to return: ";
                std::getline(std::cin, isbn);
                library.returnBook(isbn);
                break;
            }
            case 5:
                std::cout << "Exiting Library Management System.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

