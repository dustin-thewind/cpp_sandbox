//ENCRYPT.CPP
#include "encrypt.h"
#include <iostream>
vector<char> removeduplicates(vector <char> c)  
{
	vector<char> result;
	result.push_back(c[0]);          
	for (int i = 1; i < c.size(); i++)  
	{                                    
		bool add = true;
		for (int j = 0; j < result.size(); j++)
		{
			if (c[i] == result[j])
				add = false;
		}
		if (add == true)
			result.push_back(c[i]);
	}
	printcharacter(result);      
	return result;     
}
void printcharacter(vector<char> c)
{
	for (int i = 0; i < c.size(); i++)
		cout << c[i] << " ";
	cout << "\n";
}
char encrypt(vector<char> en, char c)  
{                                     
	int index = c - 'A';    
	return en[index];	

}

