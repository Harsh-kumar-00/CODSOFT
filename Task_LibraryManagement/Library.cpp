#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

class Book
{
private:
    string title, author, isbn;
    bool issued;
    time_t issueDate;

public:
    Book(string t, string a, string i) : title(t), author(a), isbn(i), issued(false), issueDate(0) {}

    void displayDetails() const
    {
        cout << "\n📘 Book Details:\n";
        cout << "Title  : " << title << "\n";
        cout << "Author : " << author << "\n";
        cout << "ISBN   : " << isbn << "\n";
        cout << "Status : " << (issued ? "Issued" : "Available") << "\n";
    }

    void markAsIssued()
    {
        issued = true;
        issueDate = time(nullptr); // store current time
    }

    void markAsReturned()
    {
        issued = false;
        issueDate = 0;
    }

    int calculateFine() const
    {
        if (!issued) return 0;
        const int allowedDays = 7;
        const int finePerDay = 5;

        time_t now = time(nullptr);
        double seconds = difftime(now, issueDate);
        int days = seconds / (60 * 60 * 24);

        if (days > allowedDays)
            return (days - allowedDays) * finePerDay;
        return 0;
    }

    // Getters
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return isbn; }
    bool isIssued() const { return issued; }
};

class Library
{
private:
    vector<Book> books;

public:
    void addBook(string title, string author, string isbn)
    {
        books.emplace_back(title, author, isbn);
        cout << "\n✅ Book added successfully!\n";
    }

    void searchByTitle(string title)
    {
        for (Book &book : books)
        {
            if (book.getTitle() == title)
            {
                book.displayDetails();
                return;
            }
        }
        cout << "\n❌ Book not found!\n";
    }

    void searchByAuthor(string author)
    {
        for (Book &book : books)
        {
            if (book.getAuthor() == author)
            {
                book.displayDetails();
                return;
            }
        }
        cout << "\n❌ Book not found!\n";
    }

    void searchByISBN(string isbn)
    {
        for (Book &book : books)
        {
            if (book.getISBN() == isbn)
            {
                book.displayDetails();
                return;
            }
        }
        cout << "\n❌ Book not found!\n";
    }

    void checkoutBook(string title)
    {
        for (Book &book : books)
        {
            if (book.getTitle() == title && !book.isIssued())
            {
                book.markAsIssued();
                cout << "\n📦 Book checked out successfully!\n";
                return;
            }
        }
        cout << "\n❌ Book not available for checkout!\n";
    }

    void returnBook(string title)
    {
        for (Book &book : books)
        {
            if (book.getTitle() == title && book.isIssued())
            {
                int fine = book.calculateFine();
                book.markAsReturned();
                cout << "\n📥 Book returned successfully!\n";
                if (fine > 0)
                    cout << "💰 Fine to be paid: ₹" << fine << "\n";
                return;
            }
        }
        cout << "\n❌ Book not found or not issued!\n";
    }

    void registerBorrower(string name, string contact)
    {
        cout << "\n👤 Borrower registered successfully!\n";
        cout << "Name    : " << name << "\n";
        cout << "Contact : " << contact << "\n";
    }

    void viewBorrowerInfo(string name)
    {
        cout << "\n👤 Borrower Info:\n";
        cout << "Name    : " << name << "\n";
        // Expand with more details in future
    }

    void displayAllBooks()
    {
        if (books.empty())
        {
            cout << "\n📚 No books in the library.\n";
            return;
        }
        for (Book &book : books)
        {
            book.displayDetails();
        }
    }
};

int main()
{
    Library lib;
    int choice;
    string title, author, isbn, name, contact;

    do
    {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Search Book by Title\n";
        cout << "3. Search Book by Author\n";
        cout << "4. Search Book by ISBN\n";
        cout << "5. List All Books\n";
        cout << "6. Register Borrower\n";
        cout << "7. Checkout Book\n";
        cout << "8. Return Book\n";
        cout << "9. View Borrower Info\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // to consume newline after int

        switch (choice)
        {
        case 1:
            cout << "Enter title: ";
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter ISBN: ";
            getline(cin, isbn);
            lib.addBook(title, author, isbn);
            break;
        case 2:
            cout << "Enter title to search: ";
            getline(cin, title);
            lib.searchByTitle(title);
            break;
        case 3:
            cout << "Enter author to search: ";
            getline(cin, author);
            lib.searchByAuthor(author);
            break;
        case 4:
            cout << "Enter ISBN to search: ";
            getline(cin, isbn);
            lib.searchByISBN(isbn);
            break;
        case 5:
            lib.displayAllBooks();
            break;
        case 6:
            cout << "Enter name: ";
            getline(cin, name);
            cout << "Enter contact: ";
            getline(cin, contact);
            lib.registerBorrower(name, contact);
            break;
        case 7:
            cout << "Enter title to checkout: ";
            getline(cin, title);
            lib.checkoutBook(title);
            break;
        case 8:
            cout << "Enter title to return: ";
            getline(cin, title);
            lib.returnBook(title);
            break;
        case 9:
            cout << "Enter borrower name: ";
            getline(cin, name);
            lib.viewBorrowerInfo(name);
            break;
        case 10:
            cout << "👋 Exiting...\n";
            break;
        default:
            cout << "❗ Invalid choice!\n";
        }
    } while (choice != 10);

    return 0;
}
