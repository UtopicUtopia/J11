#ifndef WEATHER
#define WEATHER

#include <string>
#include <json.h>
using namespace std;

//enums
enum TempDegree { K, C, F };

class Weather
{
public:
	Weather();
	Weather(string city);
	double	getMaxTemperture();
	double	getMinTemperture();
	double	getTemperture();
	double	getHumidity();
	int		getClouds();
	int		getRainPercipitation();

	string searchLocation(string semiLocationName);

	double 	toFahrenheit(double temperture, TempDegree degree);
	double 	toCelsius(double temperture, TempDegree degree);
	double 	toKelvin(double temperture, TempDegree degree);

	void getData(string city);

private:

	void setLocation(string locationName);
	

};

#endif
