//Final project week13

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include "Person.h"
#include "Laborer.h"
#include "Manager.h"
#include "Owner.h"
#include <fstream>

using namespace std;
int main();
//void menu();
void subMenu1(vector<Person*>&);// work
void subMenu2(vector<Person*>&);
void findPerson(vector<Person*>&); //work
void removePerson(vector<Person*>&);// work
void calculatePerson(vector<Person*>&);
//void SortPersons(vector<Person*>&);
//void readPersons(vector<Person*>&);
void savePersons(vector<Person*>&);

int main() {
	int choice;
	vector<Person*>persons;
	readPersons(persons);
	do {
		cout << "1. Add person" << endl;// work
		cout << "2. Find person " << endl;// work
		cout << "3. Remove person " << endl;//work
		cout << "4. Display list" << endl;
		cout << "5. Calculate average" << endl;
		cout << "6. Sort list" << endl;
		cout << "7. Quit" << endl;
		cout << "Plese, Enter your choice:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			subMenu1(persons);
			break;
		case 2:
			findPerson(persons);
			break;
		case 3:
			removePerson(persons);
			break;
		case 4:
			subMenu2(persons);
			break;
		case 5:
			calculatePerson(persons);
			break;
		case 6:
			SortPersons(persons);
			break;
		case 7:
			savePersons(persons);
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
		}
	} while (choice != 7);
	return 0;
}

void readPersons(vector<Person*>& persons) {
	ifstream file("persons.txt");
	if (!file) {
		cerr << "Error: Failed to open file" << endl;
		return;
	}
	string type;
	while (file >> type) {
		if (type == "laborer") {
			persons.push_back(new Laborer());
		}
		else if (type == "manager") {
			persons.push_back(new Manager());
		}
		else if (type == "owner") {
			persons.push_back(new Owner());
		}
		else {
			cerr << "Error: Invalid person type" << endl;
			return;
		}
	}
	file.close();
}

void subMenu1(vector<Person*>& persons) {
	int choice;
	cout << "1. Add Laborer" << endl;
	cout << "2. Add Manager" << endl;
	cout << "3. Add Owner" << endl;
	cout << " please enter your choice:";
	cin >> choice;
	cin.ignore();
	switch (choice) {
	case 1: {
		string name, ssn, birthDate, job, empId;
		double hourlySalary, hoursWorked;
		cout << "Enter the name: ";
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
	case 2:; {
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
	case 3:; {
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
	default:
		cout << "Invalid choice" << endl;
		break;
	}
}

void subMenu2(vector<Person*>& persons) {
	int choice1;
	cout << "1. All" << endl;
	cout << "2. Laborer " << endl;
	cout << "3. Manager" << endl;
	cout << "4. Owner" << endl;
	cout << "Enter your choice: ";
	cin >> choice1;
	cin.ignore();
	switch (choice1) {
	case 1: {
		cout << "All persons:" << endl;
		for (Person* person : persons) {
			//person->print();
		}
		break;
	}
	case 2:

		for (int i = 0; i < persons.size(); i++) {
			if (persons[i]->category() == "Laborer") {
				Laborer* lab = dynamic_cast<Laborer*>(persons[i]);
				cout << "Category:" << persons[i]->category() << endl;
				cout << "Enter Name:" << persons[i]->getName() << endl;
				cout << "SSN:" << persons[i]->getsoicalNumber() << endl;
				cout << "BirthDate:" << persons[i]->getBirthDate() << endl;
				cout << "Job:" << lab->getJob() << endl;
				cout << "Employee ID:" << lab->getEmpId() << endl;
				cout << "Hourly Salary:" << lab->getHourlySalary() << endl;
				cout << "Hours worked:" << lab->getHoursWorked() << endl;
			}
		}
		break;
	case 3:
		for (int i = 0; i < persons.size(); i++) {
			if (persons[i]->category() == "Manager") {
				Manager* man = dynamic_cast<Manager*>(persons[i]);
				cout << "Category:" << persons[i]->category() << endl;
				cout << "Enter Name:" << persons[i]->getName() << endl;
				cout << "SSN:" << persons[i]->getsoicalNumber() << endl;
				cout << "BirthDate:" << persons[i]->getBirthDate() << endl;
				cout << "Department:" << man->getDepartment() << endl;
				cout << "Employee ID" << man->getEmpId() << endl;
				cout << "Salary" << man->getSalary() << endl;
			}
		}
		break;
	case 4:
		for (int i = 0; i < persons.size(); i++) {
			if (persons[i]->category() == "Owner") {
				Owner* own = dynamic_cast<Owner*>(persons[i]);
				cout << "Category:" << persons[i]->category() << endl;
				cout << "Enter Name:" << persons[i]->getName() << endl;
				cout << "SSN:" << persons[i]->getsoicalNumber() << endl;
				cout << "BirthDate:" << persons[i]->getBirthDate() << endl;
				cout << "Business Percentage:" << own->getBusinessPercentage() << endl;
				cout << "Owner Date:" << own->getOwnerDate() << endl;
			}
		}
		break;
	default:
		break;
	}
}



void calculatePerson(vector<Person*>& persons) {
	/*To calculateand display the average salary for each category, you can call the calculatePerson function three times, once for each category:


	calculatePerson(persons, 1);  // Category 1
	calculatePerson(persons, 2);  // Category 2
	calculatePerson(persons, 3);  // Category 3
	Then, you can call the function three times, once for each category:

c++
Copy code
calculatePerson(persons, 1);  // Category 1
calculatePerson(persons, 2);  // Category 2
calculatePerson(persons, 3);  // Category 3
Note that the calculatePerson function should be defined before calling it. You can define it at the beginning of your program or in a separate header file.






Regenerate response

	*/
	//string category;
	int count = 0;
	double total = 0.0;
	string categories[4] = { "Laborer", "Manager", "Person", "Owner"};
	for (string category : categories) {
		count = 0;
		total = 0.0;
		for (Person* person : persons) {
			if (person->category() == category) { // Filter persons based on category
				total += person->getSalary();
				count++;
			}			
		}
		if (count > 0) {
			double average = total / count;
			cout << "Average salary for category " << category << ": " << fixed << setprecision(2) << average << endl;
		}
		else {
			cout << "No persons found in category " << category << endl;
		}
	}
	
}

/*
  This function loops over all persons in the persons vector,
  gets their salary using the getSalary method, adds it to the total variable,
  and increments the count variable. Then it calculates the average by dividing
  the total by the count and displays it using cout. If there are no persons in the vector, it displays a message saying so.*/


  /*int count = 0;
  double total = 0.0;
  for (Person* person : persons) {
	  total += person->getSalary();
	  count++;
  }
  if (count > 0) {
	  double average = total / count;
	  cout << "Average salary of all persons: " << fixed << setprecision(2) << average << endl;
  }
  else {
	  cout << "No persons found" << endl;
  }
}*/
/*void calculateAllCategories(vector<Person*>& persons) {
	calculatePerson(persons, 1);  // Category 1
	calculatePerson(persons, 2);  // Category 2
	calculatePerson(persons, 3);  // Category 3
	calculateAllCategories(persons);*/




void findPerson(vector<Person*>& persons) {
	string name;
	cout << "Enter name of person to find: ";
	cin.ignore();
	getline(cin, name);

	auto it = find_if(persons.begin(), persons.end(),
		[&name](Person* p) {return p->getName() == name; });

	if (it != persons.end()) {
		cout << "Person found in list" << endl;
	}
	else {
		cout << "Person not found in list" << endl;
	}
}



void removePerson(vector<Person*>& persons) {
	string name;
	cout << "Enter name of person to remove: ";
	cin.ignore();
	getline(cin, name);

	auto it = find_if(persons.begin(), persons.end(),
		[&name](Person* p) {return p->getName() == name; });

	if (it != persons.end()) {
		persons.erase(it);
		cout << "Person removed from list" << endl;
	}
	else {
		cout << "Person not found in list" << endl;
	}
}

void SortPersons(vector<Person*>& persons) {
	sort(persons.begin(), persons.end(), [](Person* a, Person* b) {
		return a->getName() < b->getName();

		});
}

void loadPerson(const std::string& name) {

	srand(time(0));

	std::ifstream input("persons.dat", std::ios::in);

	//std::ofstream output("fileout3.dat", std::ios::out);
	if (input.is_open()) {
		std::string personName;
		string Ssn;
		string birthDate;
		bool found = false;
		while (input >> personName >> Ssn >> birthDate) {
			if (personName == name) { // Aradığımız kişi bulunduysa
				found = true;
				//persons.push_back(new Person(file_name, Ssn, birthDate)); // نضيف الكائن الجديد الى المتجة
				//output << personName << " " << Ssn << " " << birthDate << "\n"; // Alınan datayı yazıcıdan çıkarmak için dosyaya yazıyoruz

				std::cout << "Found person: " << personName << ", " << Ssn << "Soical Number" << birthDate << "\n"; // Bulunan kişiyi ekrana yazdırıyoruz
				break;
			}
		}
		if (!found) {
			std::cerr << "Person not found!\n";
		}
		input.close();
		//output.close();
	}
	else {
		std::cerr << "Error!";
	}

}

void savePersons(vector<Person*>& persons) {
	ofstream outFile("persons.txt");
	if (!outFile.is_open()) {
		cout << "Error: could not open file" << endl;
		return;
	}
	if (persons.size() > 0) {

		outFile << "Total Persons in vector: " << persons.size() << endl;

		// iterate through the persons vector

		for (int index = 0; index < persons.size(); index++) {

			outFile << "Category: " << persons.at(index)->category() << endl;

			outFile << "Name: " << persons.at(index)->getName() << endl;

			outFile << "Social security number: " << persons.at(index)->getsoicalNumber() << endl;

			outFile << "Birth Date: " << persons.at(index)->getBirthDate() << endl;

			if (persons.at(index)->category() == "Laborer") {

				Laborer* lab = dynamic_cast<Laborer*>(persons.at(index)
					);

				outFile << "Job: " << lab->getJob() << endl;

				outFile << "Employee Id: " << lab->getEmpId() << endl;

				outFile << "Hourly salary: " << lab->getHourlySalary() << endl;

				outFile << "Hours Worked: " << lab->getHoursWorked() << endl;

			}

			else if (persons.at(index)->category() == "Manager") {

				Manager* man = dynamic_cast<Manager*>(persons.at(index)
					);

				outFile << "Department: " << man->getDepartment() << endl;

				outFile << "Employee Id: " << man->getEmpId() << endl;

				outFile << "Salary: " << man->getSalary() << endl;

			}

			else if (persons.at(index)->category() == "Owner") {

				Owner* own = dynamic_cast<Owner*>(persons.at(index)
					);

				outFile << "Business Percentage: " << own->getBusinessPercentage() << endl;

				outFile << "Owner Date: " << own->getOwnerDate() << endl;

			}

			outFile << endl << endl;

		}

	}

	
	//for (Person* person : persons) {
	//	if (Laborer* laborer = dynamic_cast<Laborer*>(person)) {
	//		outFile << "L " << laborer->getName() << " " << laborer->getBirthDate() << " " << laborer->getHourlySalary() << " " << laborer->getHoursWorked() << laborer->get() << endl;
	//	}
	//	else if (Manager* manager = dynamic_cast<Manager*>(person)) {
	//		outFile << "M " << manager->getName() << " " << manager->getBirthDate() << " " << manager->getSalary() << " " << manager->getDepartment() << endl;
	//	}
	//	else if (Owner* owner = dynamic_cast<Owner*>(person)) {
	//		outFile << "O " << owner->getName() << " " << owner->getBirthDate() << " " << owner->getBusinessPercentage() << " " << owner->getOwnerDate() << endl;
	//	}
	//}
	outFile.close();
}

