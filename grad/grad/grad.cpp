#include <iostream>
#include <iomanip>
#include <string>
#include "grad.h"

Undergraduate::Undergraduate() { sname = " "; tuition = 0; numclasses = 0; }
Undergraduate::Undergraduate(string n, double t, int nm) { sname = n; t = tuition; numclasses = nm; }
//void Undergraduate::classprice(double p){ classprice = p; }
void Undergraduate::nameset(string n) { sname = n; }
void Undergraduate::setnumclasses(int n) { numclasses = n; }
void Undergraduate::tuitionset(double cc) { tuition = cc * numclasses; }
string Undergraduate::nameget() const { return sname; }
double Undergraduate::gettuition() const { return tuition; }
int Undergraduate::getnumclasses() const { return numclasses; }
void Undergraduate::studentprint() const{
	cout << "Student name: " << sname << endl;
	cout << "Number of classes they're enrolled in: " << numclasses << endl;
	cout << "Cost of tuition: $" << tuition << endl;
}

Graduate::Graduate() { fees = 0; }
Graduate::Graduate(string n, double t, int nm, double f) :Undergraduate(n, t, nm) { fees = f; }
void Graduate::setfees(double f) { fees = f; }
double Graduate::getfees() const { return fees; }
string Graduate::nameget() const { return Undergraduate::nameget(); }
void Graduate::studentprint() const{
	cout << "Student name: " << nameget() << endl;
	cout << "Number of classes they're enrolled in: " << getnumclasses() << endl;
	cout << "Cost of tuition: $" << gettuition() << endl;
	cout << "Recurring fees are: " << getfees() << endl;
}

double Graduate::gettuition() const { return Undergraduate::gettuition() + fees; }
int Graduate::getnumclasses() const { return Undergraduate::getnumclasses(); }
