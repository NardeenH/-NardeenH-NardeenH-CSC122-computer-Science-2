#include <iostream>
#include <vector>
#include <ctime>
#include <string>
using namespace std;

void bubbleSort(vector<int>& arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
class Planet {
public:
    struct PlanetData {
        string name;
        double distanceFromSun;
        double diameter;
    };

    void addPlanet(const string& name, double distance, double diameter) {
        PlanetData planet;
        planet.name = name;
        planet.distanceFromSun = distance;
        planet.diameter = diameter;
        planets.push_back(planet);
    }

    void deletePlanet(const string& name) {
        for (auto it = planets.begin(); it != planets.end(); ++it) {
            if (it->name == name) {
                planets.erase(it);
                break;
            }
        }
    }
    void sortPlanets() {
        for (int i = 1; i < planets.size(); ++i) {
            PlanetData key = planets[i];
            int j = i - 1;
            while (j >= 0 && planets[j].distanceFromSun > key.distanceFromSun) {
                planets[j + 1] = planets[j];
                j = j - 1;
            }
            planets[j + 1] = key;
        }
    }

    void printPlanets() const {
        for (const auto& planet : planets) {
            cout << planet.name << " - " << planet.distanceFromSun << " - " << planet.diameter << endl;
        }
    }

private:
    vector<PlanetData> planets;
};


int main()
{
    vector<int> arr(10000); // sorting a vector of size 10000
    srand(time(0)); // seeding the random number generator with the current time
    for (int i = 0; i < arr.size(); i++)
        arr[i] = rand();

    clock_t start = clock();
    bubbleSort(arr);
    clock_t end = clock();

    double time = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken by non-recursive bubble sort: " << time << " seconds" << endl;
    Planet solarSystem;

    solarSystem.addPlanet("Mercury", 0.387, 4.88);
    solarSystem.addPlanet("Venus", 0.723, 12.104);
    solarSystem.addPlanet("Earth", 1.0, 12.742);
    solarSystem.addPlanet("Mars", 1.524, 6.779);
    solarSystem.addPlanet("Jupiter", 5.203, 139.822);

    cout << "Before sorting:" << endl;
    solarSystem.printPlanets();

    solarSystem.sortPlanets();

    cout << "After sorting:" << endl;
    solarSystem.printPlanets();

    solarSystem.deletePlanet("Mars");

    cout << "After deleting Mars:" << endl;
    solarSystem.printPlanets();
    return 0;
}
