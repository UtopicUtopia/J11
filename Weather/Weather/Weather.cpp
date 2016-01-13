#include "Weather.h"
#include <iostream>
using namespace std;



//public
Weather::Weather()
{
	cout << "hello, Weather!" << endl;
}
double	Weather::getMaxTemperture()
{
	return 2.5;		//examdata
}
double	Weather::getMinTemperture()
{
	return -5.2;		//examdata
}
double	Weather::getTemperture()
{
	return -3.0;	//examdata
}
double	Weather::getHumidity()
{
	return 45.0;	//examdata
}
string	Weather::getCloudstat()
{
	string a = "Clean";
	return a;
}
int		Weather::getRainPercipitation()
{
	return 5;	//examdata
}
string* Weather::searchLocation(string semiLocationName)
{
	string a[3] = { "Incheon", "Seoul", "Suwon" };
	return a;	//examdata
}

//temperture convert
double Weather::toCelsius(double temperture, TempDegree degree)
{
	double transTemp = temperture;
	switch (degree)
	{
	case TempDegree::K :
		transTemp -= 273.15;
		break;
	case TempDegree::F :
		transTemp = (temperture - 32) / 1.8;
		break;
	case TempDegree::C :
	default:
		break;
	}

	return transTemp;
}

double Weather::toFahrenheit(double temperture, TempDegree degree)
{
	double transTemp = temperture;
	switch (degree)
	{
	case TempDegree::K:
		transTemp = ( (temperture - 273.15) * 1.8) + 32;
		break;
	case TempDegree::C:
		transTemp = (temperture * 1.8) + 32;
		break;
	case TempDegree::F:
	default:
		break;
	}
	return transTemp;
}

double Weather::toKelvin(double temperture, TempDegree degree)
{
	double transTemp = temperture;
	switch (degree)
	{
	case TempDegree::F :
		transTemp = ((temperture - 32) / 1.8) + 273.15;
		break;
	case TempDegree::C :
		transTemp += 273.15;
		break;
	case TempDegree::K :
	default:
		break;
	}
	return transTemp;
}





//private
void Weather::setLocation(string locationName)
{

}