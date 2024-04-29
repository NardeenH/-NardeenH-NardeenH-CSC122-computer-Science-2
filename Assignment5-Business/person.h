#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;

class Person {
private:
    string name;
    string ssn;
    string birthDate;

public:
    string getName() {
        return name;
    }
    string getsoicalNumber() {
        return ssn;
    }
    string getBirthDate() {
        return birthDate;
    }
    void setName(string name) {
        this->name = name;
    }
    void setsoicalNumber(string ssn) {
        this->ssn = ssn;
    }
    void setBirthDate(string birthDate) {
        this->birthDate = birthDate;
    }
    virtual string category() = 0;
};
#endif