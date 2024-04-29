//Write a program that read the starting balance, interest rate and number of months from a file. 
//Example:
//1200.43  .08 60

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
 
 double balance;
 double interestrate;
 int numMonths;
 string inputfilename;
 string outputfilename;
 cout << "Enter name of input file: ";
 cin >> inputfilename;
 ifstream input(inputfilename, ios::in);
 if (input.is_open())
 {
 input >> balance >> interestrate >> numMonths;
 input.close();
 cout << "Enter name of output file: ";
 cin >> outputfilename;
 ofstream output(outputfilename, ios::out);
 int month = 1;
 interestrate = interestrate / 12.0;
 while (month <= numMonths)
 {
 output << left << setw(3) << month
 << setw(10) << fixed << setprecision(2) << balance << endl;
 balance = balance + balance * interestrate;
 month = month + 1;
 }
 output.close();
 cout << "Output is written to " << outputfilename << endl;
 }
 else
 {
 throw ( "Error! Cannot open file!\n");
 }
 
 return 0;
}
