//dbaker csc242
//random walk

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	//sets the seed for the random number generator
	srand(time(NULL)); //seed for random using time NULL

	int south = 0; //negative x axis
	int north = 2; //positive x axis
	int west = 1; //negative y axis
	int east = 3; //positive y axis
	int northsouth = 0; //indicates movement along the x axis
	int eastwest = 0; //indicates movement along the y axis
	int steps = 0; //user enters how many steps they'd like to walk
	int boxsize = 0; // user defines size of the box
	int hitthewall = 0; // keep track of how many times drunky got to the edge of the box
	
	cout << "Welcome to the drunk walk simulator! This app will simulate your walk of \n";
	cout << "inebriation in a defined box for a defined number of steps. Let's go! \n";
	cout << endl;
	cout << "Please enter the number of steps you'd like your drunk self to walk: "; 
	cin >> steps;
	cout << "Now enter the lenght of 1 side of the square you're confined in: ";
	cin >> boxsize; //user enters the length of one side of the box, which is defined as a square
	boxsize = (boxsize / 2); // split the box side length evenly between positive and negative axis
	int maxvert = boxsize; //define the max boundary of the box vertically, start from 0
	int minvert = -1 * boxsize; //define the min boundary of the box vertically, start from 0
	int maxhoriz = boxsize; //define the max boundary of the box horizontally, start from 0
	int minhoriz = -1 * boxsize; //define the max boundary of the box horizontally, start from 0

	for (int i = 0; i <=steps; i++) // do loop for STEPS amount of iterations, STEPS is defined by user
	{
		int walk = rand() % 4; // give random ints between 0 & 3, MOD 4

		if (walk == north)
		{
			if (northsouth >= maxvert) { // indicate if you've hit the wall of the box by increasing hitthewall int
				hitthewall++;
				northsouth--; // if you hit the wall, take a step back 
			}
			else {
				northsouth++;
			}
		}
		else if (walk == south)  // south is a negative 
		{
			if (northsouth <= minvert) // indicate if you've hit the wall of the box by increasing hitthewall int
			{
				hitthewall++;
				northsouth++; // if you hit the wall, take a step back, in this case you're in a negative axis so you increase to step back
			}
			else {
				northsouth--;
			}
		}
		else if (walk == east)
		{
			if (eastwest >= maxhoriz){ // indicate if you've hit the wall of the box by increasing hitthewall int
				hitthewall++;
				eastwest--; // if you hit the wall, take a step back 
			}
			else
			{
				eastwest++;
			}
		}
		else if (walk == west)
		{
			if (eastwest <= minhoriz) // indicate if you've hit the wall of the box by increasing hitthewall int
			{
				hitthewall++;
				eastwest++; // if you hit the wall, take a step back, in this case you're in a negative axis so you increase to step back
			}
			else{
				eastwest--;
			}
			
		}
	}

	//output the results of the walk
	cout << "After your drunken stumble of " << steps << " steps you've landed at: " << northsouth << " " << eastwest << endl;
	cout << "And bumped into the walls of the box " << hitthewall << " times." << endl;
	cout << "Thankfully you didn't break any bones, though. " <<endl;

	return 0;


}