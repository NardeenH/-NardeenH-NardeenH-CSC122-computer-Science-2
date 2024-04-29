#pragma once
#ifndef LIST_H
#define LIST_H


class BookList {
private:

    string* list;
    int size;
    int d;

public:
    BookList() {
        d = 2;
        size = 0;
        list = new string[d];
       
    }
};

#endif