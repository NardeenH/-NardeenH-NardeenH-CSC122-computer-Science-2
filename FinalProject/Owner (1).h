#pragma once

#ifndef OWNER_H
#define OWNER_H
#include "Person.h"
#include <iostream>
using namespace std;

class Owner : public Person {
private:
    double PercentageOfbusiness;
    string ownerDate;
public:
    double getBusinessPercentage() {
        return PercentageOfbusiness;
    }
    string getOwnerDate() {
        return ownerDate;
    }

    void setPercentageOfbusiness(double PercentageOfbusiness) {
        this->PercentageOfbusiness = PercentageOfbusiness;
    }
    void setOwnerDate(string ownerDate) {
        this->ownerDate = ownerDate;
    }
    string category() {
        return "Owner";
    }
};
#endif