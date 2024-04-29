#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Person {
protected:
    string name;
public:
    Person(string name) : name(name) {}
    virtual void display() = 0;
    string getName() const { return name; }
};

class Owner : public Person {
public:
    Owner(string name) : Person(name) {}
    void display() {
        cout << "Owner: " << name << endl;
    }
};

class Manager : public Person {
public:
    Manager(string name) : Person(name) {}
    void display() {
        cout << "Manager: " << name << endl;
    }
};

class Laborer : public Person {
public:
    Laborer(string name) : Person(name) {}
    void display() {
        cout << "Laborer: " << name << endl;
    }
};

class Company {
private:
    vector<Person*> employees;
public:
    void addPerson() {
        cout << "Enter name: ";
        string name;
        cin >> name;
        cout << "Choose the type of person you are adding:\n";
        cout << "1. Owner\n";
        cout << "2. Manager\n";
        cout << "3. Laborer\n";
        int choice;
        cin >> choice;
        switch (choice) {
        case 1:
            employees.push_back(new Owner(name));
            break;
        case 2:
            employees.push_back(new Manager(name));
            break;
        case 3:
            employees.push_back(new Laborer(name));
            break;
        default:
            cout << "Invalid choice.\n";
            break;
        }
    }

    void displayList() {
        cout << "Choose the category of person to display:\n";
        cout << "1. All\n";
        cout << "2. Owners\n";
        cout << "3. Managers\n";
        cout << "4. Laborers\n";
        int choice;
        cin >> choice;
        switch (choice) {
        case 1:
            for (auto employee : employees) {
                employee->display();
            }
            break;
        case 2:
            for (auto employee : employees) {
                Owner* owner = dynamic_cast<Owner*>(employee);
                if (owner != nullptr) {
                    owner->display();
                }
            }
            break;
        case 3:
            for (auto employee : employees) {
                Manager* manager = dynamic_cast<Manager*>(employee);
                if (manager != nullptr) {
                    manager->display();
                }
            }
            break;
        case 4:
            for (auto employee : employees) {
                Laborer* laborer = dynamic_cast<Laborer*>(employee);
                if (laborer != nullptr) {
                    laborer->display();
                }
            }
            break;
        default:
            cout << "Invalid choice.\n";
            break;
        }
    }

    void sortList() {
        sort(employees.begin(), employees.end(),
            [](Person* a, Person* b) { return a->getName() < b->getName(); });
        cout << "List sorted by name.\n";
    }

    void removePerson() {
        cout << "Enter the name of the person you want to remove: ";
        string name;
        cin >> name;
        for (auto it = employees.begin(); it != employees.end(); ++it) {
            if ((*it)->getName() == name) {
                delete* it;
                employees.erase(it);
                cout << "Person removed from the list.\n";
                return;
            }
        }
        cout << "Person not found in the list.\n";
    }
    ~Company() {
        for (auto employee : employees) {
            delete employee;
        }
    }
};
int main() {
    Company company;
    while (true) {
     
        cout << "1. Add person\n";
        cout << "2. Display list\n";
        cout << "3. Sort list\n";
        cout << "4. Remove person\n";
        cout << "5. Quit\n";
        int choice;
        cin >> choice;
        switch (choice) {
        case 1:
            company.addPerson();
            break;
        case 2:
            company.displayList();
            break;
        case 3:
            company.sortList();
            break;
        case 4:
            company.removePerson();
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice.\n";
            break;
        }
    }
}