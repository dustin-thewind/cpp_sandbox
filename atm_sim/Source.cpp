//dbaker csc242
//atm simulator

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/*
function receives balance and decrements balance by withdrawl amount
@param num1 - balance
@return - returns value of subtracting withdrawl from balance
*/

double withdrawl(double &num1)
{
	double withdbal;
	cout << "Enter how much you'd like to withdraw: $";
	cin >> withdbal;
	if (withdbal < 0) //make sure withd isn't negative, increment invalid if condition is met
	{
		cout << "Please enter a positive number for a withdrawl\n";
		//invalid++;
	}
	if (withdbal >= num1) //make sure there are sufficient funds in the account for withd, increment invalid if condition is met
	{
		cout << "There are insufficient funds for this transaction \n";
		cout << "Please try again\n";
		//invalid++;
	}
	else if (withdbal < num1 && withdbal > 0) { // if valid witdh and enough funds allow withdrawl, increase exit
		num1 = num1 - withdbal;
		//invalid = 3;
	}
	return num1;
}
/*
function receives balance and increments balance by deposit amount
@param num2 - balance
@return -returns value adding deposit to balance
*/
double deposit(double &num2)
{
	double depobal;
	cout << "Enter how much you'd like to deposit: $";
	cin >> depobal;

	if (depobal <= 0) // make sure depo isn't a negative number
	{
		cout << "You have entered a negative number, please enter a positive number to deposit funds\n";
		cout << "Please try again\n";
		//invalid++;
	}
	else  {
		num2 = num2 + depobal;
			//invalid = 3;
	}
	return num2;
}
/*
function receives two numbers and adds one to another
@param num3 - balance, first int
@param num4 - deposit, second int
@return -returns value adding deposit to balance
*/
double currbal(double &num5)
{
	double current;
	current = num5;
	return current;
}
/*
funtion displays the ATM menu
*/

void atmmenu()
{
	cout << "Type 1 to withdraw funds" << endl;
	cout << "Type 2 to deposit funds" << endl;
	cout << "Type 3 to check balance" << endl;
	cout << "Type 4 to exit ATM" << endl;
}

int main()
{
	double acctbalance = 25000; //starting balance of account
	int selection = 0; //used to initialize switch
	int pin = 0; //PIN for account
	int withd = 0; // int for withdrawls
	int depo = 0; // int for deposits
	int exit = 0; // used to control switch loops and do while loop for ATM menu
	int exitatm = 0; //used to exit ATM
	int lockout = 0; //used to track invalid inputs for PIN
	int invalid = 0; //used to track invalid input for withdrawls or deposits
	
	
	cout << "This is a simulation ATM\n";
	cout << "For the purposes of this simulation please note the following: \n";
	cout << "Your PIN is: 3498\n";
	cout << "Your starting balance is $25,000\n";
	cout << "\n";
	cout << "Let's get started!\n";
	cout << "\n";
	cout << "Welcome to Sketchy ATM! " << endl;
	cout << "======================= " << endl;
	
	do { // do this loop while exitatm < 1, if exitatm >= 1 exit program
		for (int lockout = 0; lockout < 3;) //if too many failed attempts at PIN exit program
		{
			cout << "Please enter your PIN to continue: ";
			cin >> pin;

			if (pin == 3498 && exitatm < 1) //check for valid PIN entry
			{
				do {
					cout << "Please make a selection.... \n";
					cout << "\n";
					atmmenu();
					cout << "============================\n";
					cin >> selection;
					

					switch (selection)
					{
						
					case 1:
						withdrawl(acctbalance);
						break;
					case 2:
						deposit(acctbalance);
						break;
					case 3:
						cout << "Your balance is: $" << acctbalance << endl;
						break;
					case 4:
						cout << "Exiting...... Thanks for using SketchyATM!\n";
						exit = 4;
						break;

					default:
						cout << "Please make a valid selection from the menu." << endl;
						break;
					}
				} while (exit < 4);

				exitatm = 1; // breaks loop 
				lockout = 10; // breaks loop and forces program to exit
			}
			else if (pin != 3498 && lockout < 2) //
			{
				lockout++;
				cout << "Invalid pin, please try again.\n";
				cout << "You have " << 3 - lockout << " attempts before you're locked out of the ATM.\n";
			}
			else //if 3 invalid pin entries break and exit program
			{
				lockout++;
				cout << "You have been automatically logged out after too many failed attempts" << endl;
				exitatm = 1;
			}
		}
	} while (exitatm < 1);
		
		return 0;
	}
			
	
	