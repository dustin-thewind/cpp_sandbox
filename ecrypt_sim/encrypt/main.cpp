//MAIN.CPP
#include "encrypt.h"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int main()
{
	string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	vector<char> encrypt_string;
	cout << "Enter a 7 character encryption string, one at a time, with all capital letters " << endl;
	for (int i = 0; i < 7; i++){
		char ch;
		cout << "Enter a character: ";
		cin >> ch;
		encrypt_string.push_back(ch);
	}
	vector<char> l = removeduplicates(encrypt_string);  
	printcharacter(l); 
	for (int k = 25; k > ALPHA.size() - l.size() - 1; k--)
		l.push_back(ALPHA[k]); 
	printcharacter(l);  
	string message;
	cout << "Enter the string you'd like to encrypt, in all capital letters: ";
	cin.ignore();
	getline(cin, message);
	cout << endl;
	for (int i = 0; i < message.length(); i++)
	{
		if (message[i] == ' ')
			cout << " ";
		else
			cout << encrypt(l, static_cast<char>(message[i]));
	}
	cout << endl;

	return 0;
}