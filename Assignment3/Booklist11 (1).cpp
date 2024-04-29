
// Booklist


#include <iostream>
#include <string>
#include <cstdlib>
#include "list.h"
using namespace std;


    ~BookList() {
        delete[] list;
    }

    void addBook(string title) {
        if (size == d) {
            string* temp = new string[2 * d];
            for (int i = 0; i < size; i++) {
                temp[i] = list[i];
            }
            delete[] list;
            list = temp;
            d *= 2;
        }
        list[size++] = title;
    }

    bool deleteBook(string title) {
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (list[i] == title) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            return false;
        }
        for (int i = index; i < size - 1; i++) {
            list[i] = list[i + 1];
        }
        size--;
        return true;
    }

    void displayList() {
        if (size == 0) {
            cout << "The list is empty." << endl;
        }
        else {
            for (int i = 0; i < size; i++) {
                cout << list[i] << endl;
            }
        }
    }

    friend ostream& operator<<(ostream& os, const BookList& bl) {
        for (int i = 0; i < bl.size; i++) {
            os << bl.list[i] << endl;
        }
        return os;
    }

    BookList(const BookList& other) {
        capacity = other.capacity;
        size = other.size;
        list = new string[capacity];
        for (int i = 0; i < size; i++) {
            list[i] = other.list[i];
        }
    }

    void resizeList(int newCapacity) {
        if (newCapacity < size) {
            newCapacity = size;
        }
        string* temp = new string[newCapacity];
        for (int i = 0; i < size; i++) {
            temp[i] = list[i];
        }
        delete[] list;
        list = temp;
        capacity = newCapacity;
    }
};

int main() {
    BookList bl;
    int choice;
    string title;
    do {
        cout << "Choose an option:" << endl;
        cout << "1. Add book" << endl;
        cout << "2. Delete book" << endl;
        cout << "3. Display list" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter the title of the book:" << endl;
            cin >> title;
            bl.addBook(title);
            break;
        case 2:
            cout << "Enter the title of the book to delete:" << endl;
            cin >> title;
            if (bl.deleteBook(title)) {
                cout << "Book deleted successfully." << endl;
            }
            else {
                cout << "Book not found." << endl;
            }
            break;
        case 3:
            bl.displayList();
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
        // Testing copy constructor
       BookList bl2 = bl;
    cout << "Original list:" << endl;
    cout << bl << endl;
    cout << "Copied list:" << endl;
    cout << bl2 << endl;

    // Testing resize function
    bl.resizeList(5);
    cout << "List after resizing to 5:" << endl;
    cout << bl << endl;

    return 0;
}