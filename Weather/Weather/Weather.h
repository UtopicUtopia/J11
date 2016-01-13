#ifndef WEATHER
#define WEATHER

#include <string>
using namespace std;

//enums
enum TempDegree { K, C, F };

class Weather
{
public:
	Weather();
	double	getMaxTemperture();
	double	getMinTemperture();
	double	getTemperture();
	double	getHumidity();
	string	getCloudstat();
	int		getRainPercipitation();

	string* searchLocation(string semiLocationName);

	double 	toFahrenheit(double temperture, TempDegree degree);
	double 	toCelsius(double temperture, TempDegree degree);
	double 	toKelvin(double temperture, TempDegree degree);

private:

	void setLocation(string locationName);
	

};

#endif
