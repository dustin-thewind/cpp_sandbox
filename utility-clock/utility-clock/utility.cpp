//utility.cpp
#include "utility.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


// constrcutors to initialize the private data members
Clock::Clock()
{
	hour = 0; minute = 0; second = 0; military = true;
}


Clock::Clock(int h, int m, int s, bool mi)
{
	hour = h;
	minute = m; second = s; military = mi;
}
// set and get for all data members
void Clock::setHour(int h) { hour = h; }
void Clock::setMinute(int m) { minute = m; }
void Clock::setSecond(int s) { second = s; }
void Clock::setMilitary(bool mi)  { military = mi; }
string Clock::getlocation() const { return "local"; }
int Clock::getHour() const { return hour; }
int Clock::getMinute() const { return minute; }
int Clock::getSecond() const { return second; }
bool Clock::getMilitary() const { return military; }
void Clock::print() const
{
	if (military)
		cout << setw(2) << setfill('0') << hour << ":" << setw(2) << minute << ":" << setw(2) << second << "\n";
	else
	{
		cout << ((hour >= 0 && hour <= 12) ? hour : hour % 12);
		cout << ":" << minute << ":" << second << " " << ((hour >= 0 && hour <= 12) ? "am" : "pm") << "\n";
	}
}



// Employee constructors
Employee::Employee()
{
	name = "";
	hourlyPay = 0;
}
Employee::Employee(string n, double h) :name(n), hourlyPay(h) {}  // notice the member initializer syntax for the constrcutor

void Employee::setName(string n)
{
	name = n;
}
void Employee::setHourlyPay(double h)
{
	hourlyPay = h;
}

string Employee::getName() const
{
	return name;
}
double Employee::getHourlyPay() const
{
	return hourlyPay;
}
void Employee::print() const
{
	cout << "name " << name << "  :   pay = " << hourlyPay << "\n";
}

TravelClock::TravelClock(){
	tdiff = 0;
	location = "San Diego";
}
TravelClock::TravelClock(int h, int m, int s, bool mi, int d, string loc) :Clock(h, m, s, mi), tdiff(d), location(loc){}
string TravelClock::getlocation() const
{
	return location;
}
int TravelClock::gethour() const
{
	int adjust = 0;
	adjust = tdiff + 24;
	return ((Clock::getHour() + adjust) % 24);
}
void TravelClock::print() const
{
	if (Clock::getMilitary())
		cout << setw(2) << setfill('0') << gethour() << ":" << setw(2) << getMinute() << ":" << setw(2) << getSecond() << "\n";
	else
	{
		cout << ((gethour() >= 0 && gethour() <= 12) ? gethour() : gethour() % 12);
		cout << ":" << getMinute() << ":" << getSecond() << " " << ((gethour() >= 0 && gethour() <= 12) ? "am" : "pm") << "\n";
	}
}