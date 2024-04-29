#pragma once
#ifndef MANAGER_H
#define MANAGER_H
#include "Person.h"

#include <iostream>
using namespace std;
class Manager : public Person {
private:
    // attributes
    string department;
    string empId;
    double salary;
public:
    string getDepartment() {
        return department;
    }
    string getEmpId() {
        return empId;
    }
    double getSalary() {
        return salary;
    }
    void setDepartment(string department) {
        this->department = department;
    }
    void setEmpId(string empId) {
        this->empId = empId;
    }
    void setSalary(double salary) {
        this->salary = salary;
    }
    string category() {
        return "Manager";
    }
};
#endif