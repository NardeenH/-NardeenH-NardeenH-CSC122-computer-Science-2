#include <iostream>
#include "List.h"
using namespace std;

int main()
{
    int size;
    cout << "Enter the size of the list : ";
    cin >> size;

    List objList(size);
    int* t = new int[size];
    cout << "Enter " << size << " number of elements : " << endl;
    for (int i = 0; i < size; i++) {
        cin >> t[i];
    }

    objList.setList(t);
    objList.displayList();

    objList.sortList();
    cout << "List after sorting : " << endl;
    objList.displayList();

    objList.findAverage();
    objList.findMedian();

    cout << "Enter a new size value for resizing : ";
    cin >> size;
    objList.resize(size);
    cout << "List after resizing : " << endl;
    objList.displayList();

    cout << "Enter a new size value for resizing : ";
    cin >> size;
    objList.resize(size);
    cout << "List after resizing : " << endl;
    objList.displayList();

    return 0;
}
