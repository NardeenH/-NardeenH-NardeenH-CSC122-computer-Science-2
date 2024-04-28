//Write a C++ program that will allow the user to enter a currency amount and validate that it is in a correct format.  For purposes of this program, the correct format of curency is the following:
//$1234   The $ sign followed by an integer number
//$1234.56   The $ sign followed by a real number.  If a decimal point is included in the number, there must be exactly 2 digits to the right of the decimal point
//$1,234.56  There can be commas to the right of the decimal point, but they must always be in the correct place (hint - there must be 3 integer values to the right of the comma.  No commas after the decimal point)
//-$1,234.56  There can be a negative sign before the dollar sign.

  
#include <iostream>
#include <string>
#include <regex>
using namespace std;
double validateCurrency(string input) { 
 //regex pattern("^\$\d{1,3}(,\d{3})*(\.\d{2})?$"); // Regular expression pattern to match the correct currency format
 regex pattern("\\$((\d{1,3})|(\d+))(.\d{2})");
 //regex pattern("\\$([0-9]+)|(.\\d{2})");
 //regex pattern("^\$\d{1,3}(,\d{3})*(\.\d{2})?$");
 if (regex_match(input, pattern)) { 
 input.erase(0,1); 
 return stod(input); // Convert the input to a double and return it
 }
 else {
 cout << "Invalid currency format. Please try again." << endl;
 return -1;
 }
}
int main() {
 string input; 
 do {
 cout << "Please enter a currency amount: ";
 cin >> input;
 double amount = validateCurrency(input);
 if (amount != -1) {
 cout << "Valid currency amount: " << amount << endl;
 }
 cout << "Enter another currency amount? (yes/no): ";
 cin >>input;
 } while (input == "yes");
 return 0;
