#include "grad.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){

	string n;
	double tut;
	int nc;
	double fees;
	cout << "Enter the undergraduate students name: ";
	cin >> n;
	cout << "Now enter the number of classes they'll be taking: ";
	cin >> nc;
	cout << "Now enter the cost per course: ";
	cin >> tut;
	Undergraduate u1;
	u1.nameset(n);
	u1.setnumclasses(nc);
	u1.tuitionset(tut);
	u1.studentprint();
	cout << "Enter the graduate students name: ";
	cin >> n;
	cout << "Now enter the number of classes they'll be taking: ";
	cin >> nc;
	cout << "Now enter the cost per course: ";
	cin >> tut;
	cout << "Finally, enter the student body fees: ";
	cin >> fees;
	Graduate g1;
	g1.nameset(n);
	g1.setnumclasses(nc);
	g1.setfees(fees);
	g1.tuitionset(tut);
	g1.gettuition();
	g1.studentprint();




	return 0;
}