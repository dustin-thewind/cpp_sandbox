//utility.h
#ifndef UTILITY_H
#define UTILITY_H
#include <string>
using namespace std;

// class definition for the clock. This is a bit different than the definition in the textbook. 
class Clock
{
public:
	Clock();							// the default constrcutor
	Clock(int h, int m, int s, bool mi); //constructor with parameter
	// set and get for all data members
	void setHour(int h);
	void setMinute(int m);
	void setSecond(int s);
	void setMilitary(bool mi);
	virtual int getHour() const;
	int getMinute() const;
	int getSecond() const;
	bool getMilitary() const;
	virtual string getlocation() const;
	// print method to display the value of the private data members
	virtual void print() const;
private:
	int hour;
	int minute;
	int second;
	bool military; // if true military time formt (0 - 23), if fasle the am/pm format (0 - 12)
};

class TravelClock : public Clock
{
public:
	TravelClock();
	TravelClock(int h, int m, int s, bool mi, int d, string loc);
	//override, location have new implementation
	virtual string getlocation() const;
	//override gethour
	virtual int gethour() const;
	virtual void print() const;
private:
	int tdiff;
	string location;
};

// the Employee class
class Employee
{
public:
	Employee();	// default constrcutor
	Employee(string n, double h);
	//set and get methods for the private data members
	void setName(string n);
	void setHourlyPay(double h);
	string getName() const;
	double getHourlyPay() const;
	//print method displays the value of the private data memebrs
	void print() const;
private:
	string name;
	double hourlyPay;
};

#endif