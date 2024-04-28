#include "List.h"
using namespace std;

List::List(int z) {
    size = z;
    list = new int[size];
}

void List::setList(int* t) {
    list = t;
}
int List::getSize() {
    return size;
}
int* List::getList() {
    return list;
}
void List::displayList() {
    cout << "Values in the list" << endl;
    for (int i = 0; i < size; i++) {
        cout << list[i]<< " ";
    }
}
void List::sortList() {
    int n = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (list[i] > list[j]) {
                n = list[i];
                list[i] = list[j];
                list[j] = n;
            }
        }
    }
}

//Find the average 
void List::findAverage() {
    int sum = 0;
    float avg = 0.0;
    for (int i = 0; i < size; i++)
        sum = sum + list[i];
    avg = (float)sum / size;
    cout << "Average : " << avg << endl;
}

void List::findMedian() {
    sortList();
    if (size % 2 != 0) {
        int position = (size - 1) / 2;
        cout << "Median : " << list[position] << endl;
    }
    else {
        int position = size / 2;
        int sum = list[position] + list[position - 1];
        float avgMedian = (float)sum / 2;
        cout << "Median : " << avgMedian << endl;
    }
}

void List::resize(int newSize) {
    if (newSize != size) {
        int* tlist = new int[newSize];
        if (newSize > size) {
            for (int i = 0; i < size; i++)
                tlist[i] = list[i];
        }
        else if (newSize < size) {
        size = newSize;
    }

}
