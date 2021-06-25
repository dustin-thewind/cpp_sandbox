#ifndef GRAD_H
#define GRAD_H
#include <string>
using namespace std;
class Undergraduate {
public:
	Undergraduate(); //default
	Undergraduate(string n, double t, int nm); //Overload
	void nameset(string n);//Mutator
	//void classprice(double p);
	void setnumclasses(int n); //mutator
	void tuitionset(double cc); //mutator
	virtual string nameget() const; //accessor
	virtual double gettuition() const;	//accessor
	virtual int getnumclasses() const; //accessor
	virtual void studentprint() const; //Accessor
private:
	double tuition;
	string sname;
	int numclasses;
	//double classprice;
};
class Graduate : public Undergraduate{
public:
	Graduate();
	Graduate(string n, double t, int nm, double f);
	void setfees(double f);
	double getfees() const;
	virtual string nameget() const; 
	virtual double gettuition() const;	
	virtual int getnumclasses() const;
	virtual void studentprint() const;
private:
	double fees;
};
#endif