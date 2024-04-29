#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    set<int> set1, set2, set3;
    int value;

    // Prompt user to enter values for set1
    cout << "Enter integers for Set 1 (separated by spaces, -1 to end): ";
    while (cin >> value && value != -1) {
        set1.insert(value);
    }
    cin.clear();
    cin.ignore();

    // Prompt user to enter values for set2
    cout << "Enter integers for Set 2 (separated by spaces, -1 to end): ";
    while (cin >> value && value != -1) {
        set2.insert(value);
    }
    cin.clear();
    cin.ignore();

    // Prompt user to enter values for set3
    cout << "Enter integers for Set 3 (separated by spaces, -1 to end): ";
    while (cin >> value && value != -1) {
        set3.insert(value);
    }

    // Calculate the union of all three sets
    set<int> unionSet(set1);
    unionSet.insert(set2.begin(), set2.end());
    unionSet.insert(set3.begin(), set3.end());

    // Calculate the intersection of all three sets
    set<int> intersectionSet;
    set_intersection(set1.begin(), set1.end(),
        set2.begin(), set2.end(),
        inserter(intersectionSet, intersectionSet.begin()));
    set_intersection(intersectionSet.begin(), intersectionSet.end(),
        set3.begin(), set3.end(),
        inserter(intersectionSet, intersectionSet.begin()));

    // Calculate the difference of all three sets
    set<int> diffSet;
    set_symmetric_difference(set1.begin(), set1.end(),
        set2.begin(), set2.end(),
        inserter(diffSet, diffSet.begin()));
    set_symmetric_difference(diffSet.begin(), diffSet.end(),
        set3.begin(), set3.end(),
        inserter(diffSet, diffSet.begin()));

    // Calculate the average of all values in the union set
    double sum = 0;
    for (int value : unionSet) {
        sum += value;
    }
    double avgUnion = sum / unionSet.size();

    // Calculate the average of all values in the intersection set
    sum = 0;
    for (int value : intersectionSet) {
        sum += value;
    }
    double avgIntersection = sum / intersectionSet.size();

    // Calculate the average of all values in the difference set
    sum = 0;
    for (int value : diffSet) {
        sum += value;
    }
    double avgDiff = sum / diffSet.size();

    // Print the results
    cout << "Union: ";
    for (int value : unionSet) {
        cout << value << " " << endl;
    }
    cout << "(Average: " << avgUnion << ")" << endl;

    cout << "Intersection: ";
    for (int value : intersectionSet) {
        cout << value << " ";
    }
    cout << "(Average: " << avgIntersection << ")" << endl;

    cout << "Difference: ";
    for (int value : diffSet) {
        cout << value << " ";
    }
    cout << "(Average: " << avgDiff << ")" << endl;

    return 0;
}




