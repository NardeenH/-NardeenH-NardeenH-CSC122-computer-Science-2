#pragma once
#include <iostream>
using namespace std;
class List {
private:
    int size;
    int* list;
public:
    List(int z);
    void resize(int newSize);
    void setList(int* t);
    int getSize();
    int* getList();
    void displayList();
    void sortList();
    void findAverage();
    void findMedian();
    ;
};