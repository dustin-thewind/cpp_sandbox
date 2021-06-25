#include <iostream>
#include <cmath>
using namespace std;

int main()

{
	double ar;
	double len;
	int returnValue;

	cout << "Please enter area: " << endl; //prompt for input
	cin >> ar;

	if (ar < 0){ //check to make sure area is >= 0
		cout << "Error: negative area. \n";
		returnValue = 1;
	}

	else
	{
		len = sqrt(ar); //the area is >= 0
		cout << "The lenght of the side of the square is " << len << ".\n";
	}

	return returnValue;

}


