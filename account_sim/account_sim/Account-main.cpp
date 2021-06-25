#include "Account.h"
#include <string>
#include <array>
#include <iostream>

using namespace std;
/*
searches array for user name, return  if not found
@param Account *arr[] - array to search
@param int arr_len - length of array to search
@param string usern - username to search for
*/

const int find_user(Account array[], int size, string search){
	for (int i = 0; i < size; i++)
		if (array[i].get_username() == search){
			return i;
		}
	return -1;
}
/*
*prints out all usernames in an array
*@param print_array - the array to print
*@param size - the size of the array
*/
void print_array(Account *print_array, int size){
	for (int i = 0; i < size; i++)
		cout << print_array[i].get_username() << endl;
}
/*
*searches array for username and adds user if not found, returns error if username is already found
*uses find_user to do the searching
*otherwise prints a message saying user already exists
*@param add_me - account to add
*@param arr_orig - original array
*@param size_arr - size of original array
@param search user - user to search for in original array
@param user_found - controls entering the IF loop if user is found, else says user already exists
*/
void add_client(Account &add_me, Account *&arr_orig, unsigned int &size_arr){
	int new_arr_size = size_arr + 1;
	string search_user = "";
	int user_found;
	search_user = add_me.get_username();//pull the username out of the account to add
	user_found = find_user(arr_orig, size_arr, search_user); //return value of find_user search function
	if (user_found == -1){ //start here if user isn't found
		Account *temp = new Account[size_arr]; //temp holding space
		for (unsigned int i = 0; i < size_arr; i++){
			temp[i] = arr_orig[i]; //move content from orignal array into temp array
		}
		delete[] arr_orig; //clear the contents of original array
		arr_orig = new Account[new_arr_size]; //redeclare size of the array by 1 for added user
		for (unsigned int j = 0; j < size_arr; j++){
			arr_orig[j] = temp[j]; //set contents of "new" original array to temp array
		}
		
		arr_orig[size_arr] = add_me; //set last index of "new" original array to content of add_me
		size_arr++;
		delete[] temp; //clear content of temp array
	}
	else {
		cout << "Cannot add user, user already exists! Please select a unique username."<<endl;
	}
}
/*
*searches array for username and removes user if found, returns error if username is not found
*uses find_user to do the searching
*otherwise prints a message saying user not found
*@param remove_me - account to add
*@param arr_orig - original array
*@param size_arr - size of original array
@param search user - user to search for in original array
@param user_found - controls entering the IF loop if user is found, else says user already exists
*/
void remove_client(Account &remove_me, Account *&arr_orig, unsigned int &size_arr){
	int new_arr_size = size_arr - 1;
	Account delete_marker("DELETE", "DELETE", "USER_DELETE_MARKER", 0);
	string search_user = "";
	int user_found;
	search_user = remove_me.get_username();//pull the username out of the account to remove
	user_found = find_user(arr_orig, size_arr, search_user); //return index find_user search function
	if (user_found >= 0){ //start here if user is found
		Account *temp = new Account[size_arr]; //temp holding space
		for (unsigned int i = 0; i < size_arr; i++){
			temp[i] = arr_orig[i]; //move content from orignal array into temp array
			if (i == user_found){ //create marker for account to remove
				temp[i] = delete_marker;
			}
		}
		delete[] arr_orig; //clear the contents of original array
		arr_orig = new Account[size_arr]; //redeclare size of the array by -1 for removed user
		for (unsigned int j = 0; j < size_arr; j++){
			arr_orig[j] = temp[j];
			if (j == user_found){
				;
			}
		}
		delete[] temp; //clear content of temp array
	}
	else if (user_found == -1) {
		cout << "Unable to remove user, user doesn't exist! Please enter a valid user name" << endl;
	}
}

	/*
	* Displays an ATM menu
	*/
	void atm_menu(){
		cout << "Type 1 to withdraw funds" << endl;
		cout << "Type 2 to deposit funds" << endl;
		cout << "Type 3 to check balance" << endl;
		cout << "Type 4 to exit ATM" << endl;
	}

	int main(){

		Account ac1("John", "Smith", "jsmith94", 100.0);
		Account ac2("Hurr", "Durr", "durrhurr", 100);
		Account ac3("Foo", "Bar", "barr_foo", 100);
		Account ac4("Mootsy", "Tootsy", "moots_toots", 100);
		Account ac5("Jalajengo", "Murph", "jmurph", 100);
		Account ac6("Bacon", "Pancake", "best-ever", 100);
		Account ac7("The", "Dude", "white_russian", 100);
		Account ac8("Captain", "Crunch", "cinnamon-crack", 100);
		Account ac9("Spinkled", "Gerkin", "theycallmecucumber", 100);
		Account ac10("Donkey", "Kong", "smashingbarrles", 100);
		Account *acct_ptr = new Account("Herpy", "Derpy", "derpman53", 100.00);
		Account ac11("Princess", "Beardly", "beard_lady", 100);
		Account ac12("Party", "Monster", "best-ever", 100);
		Account ac13("Finn", "TheHuman", "adventurous_one", 100);
		acct_ptr->print_acct_info();
		acct_ptr->credit_to(100);
		acct_ptr->print_acct_info();
		acct_ptr->debit_from(300);
		acct_ptr->print_acct_info();
		ac1.print_acct_info();
		acct_ptr->credit_to(1000.00);
		acct_ptr->print_acct_info();
		acct_ptr->debit_from(200.00);
		acct_ptr->print_acct_info();
		//declare new array 
		//@param array_size - size of the array
		const int array_size = 10;//set the size of the accounts array
		unsigned int array_size_dyn = 10; //track changes to the size of the array with adds/deletes
		Account *account_array;
		account_array = new Account[array_size];
		Account*temp_array;
		temp_array = new Account[array_size + 1];
		//populate the array
		account_array[0] = ac1;
		account_array[1] = ac2;
		account_array[2] = ac3;
		account_array[3] = ac4;
		account_array[4] = ac5;
		account_array[5] = ac6;
		account_array[6] = ac7;
		account_array[7] = ac8;
		account_array[8] = ac9;
		account_array[9] = ac10;
		add_client(ac12, account_array, array_size_dyn); //add user with duplicate name, should throw error
		//print_array(account_array, array_size_dyn);
		add_client(ac11, account_array, array_size_dyn); //add user with username = beard_lady
		//cout << endl;
		//print_array(account_array, array_size_dyn);
		remove_client(ac2, account_array, array_size_dyn); //remove user with username = durrhurr
		print_array(account_array, array_size_dyn);
		remove_client(ac13, account_array, array_size_dyn); //remove user with username = adventurous_one - should throw error since it doesn't exist
		print_array(account_array, array_size_dyn);
		/*
		ATM system variables
		*@param user_location - holds index location returnd from find_user function
		*@param selection - selection of menu item in ATM switch
		*@param withd - amount to withdraw
		*@param depo - amount to deposit
		*@param exit - controls do while loop for ATM switch, when exit = 4 the loop breaks
		*@param - username entered by user, searc the array for this name
		*/
		string searchname = " ";
		int user_location = 0;
		int selection = 0;
		int withd = -1;
		int depo = -1;
		int exit = -1;
		/*
		*Start ATM process
		*menu is only presented after a valid username is entered
		*/
		while (1 < 2){ //stay in this loop infinitely, until the user closes the program
			cout << "Enter username: ";
			cin >> searchname; //name to search for 
			// call find_user function, returns position of index if found, -1 if not found
			user_location = find_user(account_array, 3, searchname);
			if (user_location == -1) //return message if the user isn't found
				cout << "user " << searchname << " not found! Please try again.." << endl;

			else if (user_location >= 0){ //enter the loop if the user is found
				do { //stay here until the user choses option 4 to exit the menu
					cout << "Please make a selection.... \n";
					cout << "\n";
					atm_menu();
					cout << "============================\n";
					cin >> selection;
					switch (selection)
					{

					case 1:
						cout << "Enter how much you'd like to withdraw: ";
						cin >> withd;
						account_array[user_location].debit_from(withd); //withdraw the funds based on user request
						break;
					case 2:
						cout << "Enter how much you'd like to deposit ";
						cin >> depo;
						account_array[user_location].credit_to(depo); //deposit the funds based on user request
						break;
					case 3:
						cout << "Your balance is: $" << account_array[user_location].get_balance(); //retun the balance of the account
						cout << endl;
						break;
					case 4:
						cout << "Returning to Main Menu..... Thanks for using SketchyATM!\n";
						exit = 4;// if user selects option four the do/while loop exits and the menu exits
						break;

					default: //default case
						cout << "Please make a valid selection from the menu." << endl;
						break;
					}
				} while (exit < 4);//stay here until the user choses option 4 to exit the menu
			}
		}
		return 0;
	}
