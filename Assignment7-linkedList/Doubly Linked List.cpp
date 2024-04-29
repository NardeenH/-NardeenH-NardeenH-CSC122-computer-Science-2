
#include <iostream>
#include "Linkedlist1.h"

void menu() {
    cout << "1. Add Value" << endl;
    cout << "2. Delete Value" << endl;
    cout << "3. Display List(forward)" << endl;
    cout << "4. Display List(backward)" << endl;
    cout << "5. Quit" << endl;
}
int input() {
    int num = 0;
    while (true) {
        cout << "Enter choice: ";
        cin >> num;
        if (num >= 1 && num <= 5)
            break;
        cout << "Invalid choice!" << endl;
    }
    return num;
}
int main() {
    LinkedList list;
    int choice = 0;
    do {
        menu();
        choice = input();
        int data;
        if (choice == 1) {
            cout << "Enter data to add into list: ";
            cin >> data;
            list.addValue(data);
        }
        else if (choice == 2) {
            cout << "Enter data to delete frome list: ";
            cin >> data;
            list.deleteValue(data);
        }
        else if (choice == 3) {
            list.displayListForward();
        }
        else if (choice == 4) {
            list.displayListBackward();
        }
    } while (choice != 5);
}
