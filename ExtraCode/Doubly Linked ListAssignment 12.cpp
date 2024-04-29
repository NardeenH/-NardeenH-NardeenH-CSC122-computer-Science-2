
#include <iostream>
#include "Linkedlist1.h"


int main() {
    int number;

    cout << "Input Number: ";
    cin >> number;

    if (is_prime(number)) {
        cout << number << " is prime." << endl;
    }
    else {
        cout << "Prime Factorization: " << endl;
        DoublyLinkedList factors = prime_factorization(number);
        for (int i = 0; i < factors.get_size(); i++) {
            cout << factors[i];
            if (i < factors.get_size() - 1) {
                cout << "*";
            }
        }
        cout << endl;
    }

    return 0;
}
