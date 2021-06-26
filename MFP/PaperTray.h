/*
Team Abstract Giraffe All-in-One Printer Model
CSC300
July 2015
This code by Adam Bell
*/

#ifndef PAPERTRAY_H
#define PAPERTRAY_H

#include "Exceptions.h"

/**
Simulates the paper tray
<br>
Can ask for hasPaper() to find if there is paper and
use addPaper(int) to add paper to the tray
<br>
May throw the OutOfPaper exception
*/
class PaperTray
{
public:
	/**
	Default Constructor.  Initializes with 10 pages
	*/
	PaperTray();

	/**
	Param Constructor.
	@param initialSheetsOfPaper hte number of pages in the paper tray
	*/
	PaperTray(int initialSheetsOfPaper);

	/**
	Destructor - does nothing
	*/
	virtual ~PaperTray();
	

	/**
	Returns if the paper tray has paper
	@return true it has paper false it is out
	*/
	bool hasPaper();

	/**
	Adds paper to the paper tray
	@param numSheetsOfPaper the num,ber of sheets of paper to add to the tray
	*/
	void addPaper(int numSheetsOfPaper);

	/**
	Uses a single page of paper
	*/
	void usePage();

private:
	int paperCount;
};

#endif //PAPERTRAY_H