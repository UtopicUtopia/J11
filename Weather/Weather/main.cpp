#include <iostream>
#include "Weather.h"

using namespace std;

void jsonFileToObject(string fileLocation)
{

}

int main()
{
	Weather w1;

	/*
	double c = -10.0;
	double f = 45.0;
	double k = 300.0;

	cout << "45.0 F to C : " << w1.toCelsius(f, F) << endl;
	cout << "300.0 K to C : " << w1.toCelsius(k, K) << endl;

	cout << "-10.0 C to F : " << w1.toFahrenheit(c, C) << endl;
	cout << "300.0 K to F : " << w1.toFahrenheit(k, K) << endl;

	cout << "-10.0 C to K : " << w1.toKelvin(c, C) << endl;
	cout << "45.0 F to K : " << w1.toKelvin(f, F) << endl;
	*/
	string location;
	cin >> location;
	//cout << w1.searchLocation(location) << endl;

	w1.getData("incheon");

	return 0;
}