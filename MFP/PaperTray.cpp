#include "PaperTray.h"


PaperTray::PaperTray()
:paperCount(10)
{}


PaperTray::PaperTray(int initialSheetsOfPaper)
:paperCount(initialSheetsOfPaper)
{}


PaperTray::~PaperTray()
{}


bool PaperTray::hasPaper()
{
	if (paperCount > 0)
		return true;
	else
		return false;
}


void PaperTray::addPaper(int numSheetsOfPaper)
{
	paperCount += numSheetsOfPaper;
}

void PaperTray::usePage()
{
	if (hasPaper())
		--paperCount;
	else
		throw OutOfPaper("This paper tray is empty");
}
