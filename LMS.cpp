#include<iostream>
#include<cstring>
using namespace std;

class Book {
public:
    int id;
    char name[100];
    char author[100];
    int price;
    int pages;
    char student[100];

    void input() {
        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Book Name: ";
        cin.getline(name, 100);
        cout << "Enter Author Name: ";
        cin.getline(author, 100);
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Pages: ";
        cin >> pages;
        cin.ignore();
        cout << "Enter Borrowing Student Name: ";
        cin.getline(student, 100);
    }

    void display() const {
        cout << "\nBook ID: " << id
             << "\nBook Name: " << name
             << "\nAuthor: " << author
             << "\nPrice: " << price
             << "\nPages: " << pages
             << "\nBorrowed by: " << student << endl;
    }
};

// Linear Search by Book ID
void searchByID(Book books[], int count, int id) {
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            cout << "\nBook Found:\n";
            books[i].display();
            found = true;
            break;
        }
    }
    if (!found) cout << "\nBook with ID " << id << " not found.\n";
}

//  Linear Search by Student Name
void searchByStudent(Book books[], int count, const char* student) {
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].student, student) == 0) {
            cout << "\nBook Found:\n";
            books[i].display();
            found = true;
        }
    }
    if (!found) cout << "\nNo books found for student " << student << ".\n";
}

//  Bubble Sort by Price
void sortByPrice(Book books[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (books[j].price > books[j + 1].price) {
                swap(books[j], books[j + 1]);
            }
        }
    }
    cout << "\nBooks sorted by price.\n";
}

int main() {
    Book books[20];
    int count = 0;
    int choice;

    while (true) {
        cout << "\n--- Library Menu ---\n";
        cout << "1. Add Book\n2. Display All Books\n3. Search by Book ID\n";
        cout << "4. Search by Student Name\n5. Sort by Price\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (count < 20) {
                books[count].input();
                count++;
            } else {
                cout << "Library is full.\n";
            }
            break;
        case 2:
            for (int i = 0; i < count; i++) {
                books[i].display();
            }
            break;
        case 3: {
            int id;
            cout << "Enter Book ID to search: ";
            cin >> id;
            searchByID(books, count, id);
            break;
        }
        case 4: {
            char name[100];
            cin.ignore();
            cout << "Enter Student Name to search: ";
            cin.getline(name, 100);
            searchByStudent(books, count, name);
            break;
        }
        case 5:
            sortByPrice(books, count);
            break;
        case 6:
            cout << "Exiting... \n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}