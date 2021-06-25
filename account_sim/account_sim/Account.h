#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

using namespace std;
/**
* account is a bank account
* @param first_name is customer first name
* @param last_name is customer last name
* @param account_balance is the balance of the customers account
*@param string user_name is the clients unique username for the account
*/
class Account
{
public:
	Account(); //default constructor
	~Account(); //I AM THE DESTRUKTOR
	Account(string first, string last, string un, double bal);
	void set_first_name(string fn);
	void set_last_name(string ln);
	void set_user_name(string usern);
	void debit_from(double d);
	void credit_to(double c);
	const string get_first_name();
	const string get_username();
	const double get_balance();
	void const print_acct_info();
private:
	string first_name;
	string last_name;
	double account_balance;
	string user_name;

};

#endif