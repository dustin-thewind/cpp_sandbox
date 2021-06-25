//car.cpp
#include "car.h"
#include <iostream>
#include <string>

using namespace std;

Car::Car(){
	make = "VW";
	year = 1969;
	speed = 75;
}
Car::Car(string m, int yr, double spd){
	make = m;
	year = yr;
	speed = spd;
}
void Car::accl(int acc){
	speed = speed + acc;
}
void Car::dccl(int dcc){
	speed = speed - dcc;
}
void Car::setspd(int sp){
	speed = sp;
}
string Car::getmake() const{
	return make;
}
int Car::getyear() const{
	return year;
}
double Car::getspd() const{
	return speed;
}
void Car::getcarinfo()const{
	cout << "make " << make << " year " << year << " speed " << speed << endl;
}
