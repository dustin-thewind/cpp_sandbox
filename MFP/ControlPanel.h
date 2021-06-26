/*
Team Abstract Giraffe All-in-One Printer Model
CSC300
July 2015
*/


#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H
#include "Scanner.h"
#include <string>

class ControlPanel
{
public:
	ControlPanel(Scanner& sC);
	virtual ~ControlPanel() throw();

	/*
	behavior? 
	*/
	void errorMessage(std::string message);
	void pressFaxButton();
	void pressScanButton();
	void pressCopyButton(int numCopies, bool collate);
private:
	Scanner& scanner;
};

#endif //CONTROLPANEL_H
