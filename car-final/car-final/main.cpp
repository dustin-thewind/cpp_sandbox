//main.cpp
#include "car.h"
#include <iostream>
#include <string>
#include <vector>

double faster(vector <Car> &a){
	if (a[0].getspd() > a[1].getspd()){
		cout << a[0].getcarinfo << "is faster than " << a[1].getcarinfo;
	}
	else {
		cout << a[1].getcarinfo << "is faster than " << a[0].getcarinfo;
	}
}

using namespace std;

int main()
{
	vector<Car> cv1(2);
	Car c1("VW", 2015, 150);
	Car c2("Audi", 2016, 204);
	Car *cptr1;
	cptr1 = NULL;
	Car *cptr2;
	cptr2 = NULL;
	cptr1 = c1;
	c1.accl(10);
	c1.accl(15);
	cout << c1.getspd() << endl;
	c1.getcarinfo();
	faster(cptr1);


	return 0;
}