//main.cpp
#include <iostream>
#include<string>
#include <vector>
#include "utility.h"

using namespace std;

void printVector(vector<int>& temp)
{
	temp[0] = 1000;
	temp[1] = 1001;
	for (int i = 0; i < temp.size(); i++)
		cout << "l[" << i << "]=" << temp[i] << "\n";
}

int main()
{
	/*Clock c1;  // create or instantiate a Clock object using the default constrcutor. Call it c1
	Clock c2(18, 45, 10, true); // create or instantiate a Clock object using the constrcutor with parameter. Call it c2
	c1.print();  // call the print method in c1 object
	c2.print();
	c2.setMilitary(false); //call the setMilitary method in c2 object
	c2.print();
	vector<Clock> myC(3); //  declare a vector of three Clock objects myC[0]..myC[2], all default objects
	myC[0].print();  // call the print method of the clock object at index 0.
	myC[1] = Clock(3, 50, 44, false);
	myC[1].print();
	vector<Clock *> cptr(2);  // declare a vector of two Clock pointer
	cptr[0] = NULL;  // set pointers to NULL
	cptr[1] = NULL;
	cptr[0] = &myC[1]; // Clock pointer at index zero points to the clock object at index 1 of myC. Note the use of address operator "&"
	cptr[0]->print(); // use the pointer to call the method print. Note the "->" operator
	cptr[1] = new Clock(22, 15, 30, true);  // dynamically allocate a clock objext and have cptr[1] point to it.
	cptr[1]->print();
	cptr[1]->setMilitary(false);
	cptr[1]->print();
	delete cptr[1]; // delete the dynamically allocated clock object.
	cptr[1] = NULL;
	vector<Employee> e(2);
	e[0].print();
	e[1].print();
	vector<Employee *> eptr(2);
	eptr[0] = NULL;
	eptr[1] = NULL;
	eptr[0] = new Employee("Jim", 22.5);
	eptr[1] = new Employee("kim", 20.5);
	for (int i = 0; i < eptr.size(); i++)
	eptr[i]->print();

	int x = 22;
	double y = 5.6;
	string s = "Hello";
	cout << "x = " << x << " y = " << y << "s = " << s << "\n";
	// vector is an object
	vector<int> l(3); // declares l that holds three integer variables l[0], l[1], l[2]
	l[0] = 40;
	l[1] = 22;
	l[2] = 100;
	cout << "vector size is " << l.size() << "\n";
	printVector(l);
	cout << "l[0]=" << l[0] << "\n"; */

	Clock c1(15, 34, 12, true);
	cout << c1.getlocation();
	c1.print();
	TravelClock tc;
	TravelClock tc1(4, 15, 15, true, 3, "NYC");
	cout << tc1.getMinute() << endl;
	cout << tc1.getlocation() << endl;
	cout << c1.getlocation() << endl;
	cout << c1.getHour() << endl;
	cout << tc1.gethour() << endl;
	TravelClock tc2(1, 10, 10, true, -4, "HI");
	cout << tc2.gethour() << endl;
	tc2.setMilitary(false);
	cout << tc2.gethour() << endl;
	tc2.print();
	Clock c2 = tc1;
	c2.print();
	//tc1 = c1; //not valid

	//polymorphism / dynamic binding
	Clock *cptr = NULL; //a pointer of the base class type
	cptr = &c1; //make cptr point to clock c1
	cptr->print();
	cptr = &tc1;
	cptr->print();

	vector<Clock *> cp(3);
	cp[0] = new Clock(3, 5, 6, false);
	cp[1] = new TravelClock(23, 15, 34, true, 5, "AK");
	cp[2] = new TravelClock(5, 13, 25, false, -3, "BO");

	for (int i = 0; i < cp.size()-1; i++){
		cp[i]->print();
	}



	return 0;
}