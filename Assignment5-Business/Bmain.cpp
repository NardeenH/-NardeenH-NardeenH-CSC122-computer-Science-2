//In this assignment, you will be creating a list of people and their respective positions within a company (owner, management, labor).

//Start off by creating a base class called Person.  This class should contain a name, social security number and birth date as well as the appropriate accessors and mutators.

//From the Person class, derive a Laborer class that also includes job, employee id, hourly salary and hours worked.  (With accessors and mutators)

//From the Person class, derive a Manager class that also includes department, employee id, salary (With accessors and mutators)

///From the Person class, derive an Owner class that also includes the percentage of the business they own and the date they became an owner (With accessors and mutators)

//For each of the derived classes, also provide a function that describes what category the person is in (Laborer, Owner, Manager)

//Write a program that will display a menu allowing the user to add laborers, managers and owners. As the user enters the information to each, it will be added to a vector.  There should be a menu option to display the vector which will show all data for all entries in the vector.  Checkout example6.C from the videos for an example.  There should also be an option to quit.

#include <iostream>
#include <string>
#include <vector>
#include "person.h"
#include "Laborer.h"
#include "manger.h"
#include "owner.h"

using namespace std;

void menu();
void menu() {
 
    cout << "1. Add Laborer" << endl;
    cout << "2. Add Manager" << endl;
    cout << "3. Add Owner" << endl;
    cout << "4. END" << endl;
}

int main()
{
    int choice;
    // declare a vector of Person
    vector<Person*> persons;
    do {
        menu();
        // get choice from user
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1: {
            string name, ssn, birthDate, job, empId;
            double hourlySalary, hoursWorked;
            cout << "Enter name: ";
            //cin >> name;
            getline(cin, name);
            cout << "Enter social security number: ";
            getline(cin, ssn);
            cout << "Enter birth date: ";
            getline(cin, birthDate);
            cout << "Enter job: ";
            getline(cin, job);
            cout << "Enter employee id: ";
            getline(cin, empId);
            cout << "Enter hourly salary: ";
            cin >> hourlySalary;
            cin.ignore();
            cout << "Enter hours worked: ";
            cin >> hoursWorked;
            Laborer* lab = new Laborer();
            lab->setName(name);
            lab->setsoicalNumber(ssn);
            lab->setBirthDate(birthDate);
            lab->setJob(job);
            lab->setEmpId(empId);
            lab->setHourlySalary(hourlySalary);
            lab->setHoursWorked(hoursWorked);
            persons.push_back(lab);
            break;
        }
        case 2: {
            string name, ssn, birthDate, department, empId;
            double salary;
            cout << "Enter name: ";
            getline(cin, name);
            cout << "Enter social security number: ";
            getline(cin, ssn);
            cout << "Enter birth date: ";
            getline(cin, birthDate);
            cout << "Enter department: ";
            getline(cin, department);
            cout << "Enter employee id: ";
            getline(cin, empId);
            cout << "Enter salary: ";
            cin >> salary;
            cin.ignore();
            Manager* man = new Manager();
            man->setName(name);
            man->setsoicalNumber(ssn);
            man->setBirthDate(birthDate);
            man->setDepartment(department);
            man->setEmpId(empId);
            man->setSalary(salary);
            persons.push_back(man);
            break;
        }
        case 3: {
            string name, ssn, birthDate, ownDate;
            double businessPercentage;
            cout << "Enter name: ";
            getline(cin, name);
            cout << "Enter social security number: ";
            getline(cin, ssn);
            cout << "Enter birth date: ";
            getline(cin, birthDate);
            cout << "Enter business Percentage: ";
            cin >> businessPercentage;
            cin.ignore();
            cout << "Enter the date you became an owner: ";
            getline(cin, ownDate);
            Owner* owner = new Owner();
            owner->setName(name);
            owner->setsoicalNumber(ssn);
            owner->setBirthDate(birthDate);
            owner->setPercentageOfbusiness(businessPercentage);
            owner->setOwnerDate(ownDate);
            persons.push_back(owner);
            break;
        }
        case 4: {
            cout << endl;
            // if there are items in vector
            if (persons.size() > 0) {
                cout << "Total Persons in vector: " << persons.size() << endl;
                // iterate through the persons vector
                for (int index = 0; index < persons.size(); index++) {
                    cout << "Category: " << persons.at(index)->category() << endl;
                    cout << "Name: " << persons.at(index)->getName() << endl;
                    cout << "Social security number: " << persons.at(index)->getsoicalNumber() << endl;
                    cout << "Birth Date: " << persons.at(index)->getBirthDate() << endl;
                    if (persons.at(index)->category() == "Laborer") {
                        Laborer* lab = dynamic_cast<Laborer*>(persons.at(index));
                        cout << "Job: " << lab->getJob() << endl;
                        cout << "Employee Id: " << lab->getEmpId() << endl;
                        cout << "Hourly salary: " << lab->getHourlySalary() << endl;
                        cout << "Hours Worked: " << lab->getHoursWorked() << endl;
                    }
                    else if (persons.at(index)->category() == "Manager") {
                        Manager* man = dynamic_cast<Manager*>(persons.at(index));
                        cout << "Department: " << man->getDepartment() << endl;
                        cout << "Employee Id: " << man->getEmpId() << endl;
                        cout << "Salary: " << man->getSalary() << endl;
                    }
                    else if (persons.at(index)->category() == "Owner") {
                        Owner* own = dynamic_cast<Owner*>(persons.at(index));
                        cout << "Business Percentage: " << own->getBusinessPercentage() << endl;
                        cout << "Owner Date: " << own->getOwnerDate() << endl;
                    }
                    cout << endl << endl;
                }
            }
            else {
                cout << "No persons added to vector" << endl;
            }
            //cout << "Thank you." << endl;
            break;
        }
        default:
            cout << "Invalid choice" << endl;
            break;
        }

    } while (choice != 4);

    return 0;
}
