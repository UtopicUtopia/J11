#include "Weather.h"
#include <json\json.h>
#include <iostream>
#include <fstream>
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
int	Weather::getClouds()
{
	return 80;
}
int		Weather::getRainPercipitation()
{
	return 5;	//examdata
}

//search location
string Weather::searchLocation(string semiLocationName)
{
	ifstream listFile("./resource/city.list.json");
	if (!listFile.is_open())
	{
		cerr << "ERROR 001 : file open Error\n";
		return NULL;
	}
	
	Json::Value root;
	Json::Reader reader;
	while (!listFile.eof())
	{
		string line;
		getline(listFile, line);
		bool parsingSuccessful = reader.parse(line, root);
		if (!parsingSuccessful)
		{
			cerr << "ERROR 002 : json parsing Error\n";
			return NULL;
		}

		string cityName = root.get("name", "noname").asString();
		if (cityName == semiLocationName)
		{
			return root.get("_id", "noid").asString();
		}
	}

	return NULL;	
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