//CAR_H
#ifndef CAR_H
#define CAR_H
#include <string>

using namespace std;

class Car
{
public:
	Car(); //Default constructor
	Car(string m, int yr, double spd); //Overloaded
	void setspd(int sp);
	void accl(int acc);
	void dccl(int dcc);
	string getmake() const; //Accessor
	double getspd() const;
	int getyear() const; //Accessor
	void getcarinfo() const; //Accessor
private:
	double speed;
	int year;
	string make;
};
#endif	