#include "Account.h"
#include <iostream>
#include <string>

Account::Account(){ first_name = "John"; last_name = "Doe"; account_balance = 0.00; } //default constructor
Account::Account(string first, string last, string un, double bal) { first_name = first; last_name = last; user_name = un; account_balance = bal; }
Account::~Account(){ cout << "Removing object " << user_name << endl; }
void Account::set_first_name(string fn) { fn = first_name; }
void Account::set_last_name(string ln) { ln = last_name; }
void Account::set_user_name(string usern) { user_name = usern; }
void Account::debit_from(double d){ account_balance = account_balance - d; } //decrement account balance @param double d - the amount to decrement by
void Account::credit_to(double c) { account_balance = account_balance + c; } //increment account balance @param double c - the amount to increment by
const string Account::get_first_name() { return first_name; }
const string Account::get_username() { return user_name; }
const double Account::get_balance(){ return account_balance; }
void const Account::print_acct_info(){ cout << "Name: " << first_name << ", " << last_name << " || username: " << user_name << " || Account Balance: " << account_balance << endl; }