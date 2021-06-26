

#ifndef PRINTENGINE_H
#define PRINTENGINE_H

#include "OutputDevice.h"
#include "PaperTray.h"
#include "Exceptions.h"
#include "ControlPanel.h"
#include <string>
#include <iostream>
#include <vector>

/**
Simulate the printer
<br>
There is no default constructor, you must construct it with a pointer to a paper tray
<br>
May throw the OutOfPaper exception
<br>
StartJob(Job*) to print
*/
class PrintEngine : public OutputDevice
{
public:
	/**
	Constructor
	@param pT the paper tray to use
	*/
	PrintEngine(PaperTray* pT, ControlPanel* cP);

	/**
	Destructor - delete the paper tray and control pannel
	*/
	virtual ~PrintEngine() throw();

	/**
	Starts the Job
	May throw the OutOfPaper exception
	@param pJob a pointer to the job
	*/
	void StartJob(Job *pJob);
	
private:
	PaperTray* m_paperTray;
	ControlPanel* m_controlPanel;

	/**
	Hiding these
	*/
	PrintEngine();
	PrintEngine(const PrintEngine& other);
	PrintEngine& operator=(const PrintEngine& right);
};

#endif //PRINTENGINE_H
