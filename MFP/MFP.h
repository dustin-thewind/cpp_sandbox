

#ifndef MFP_H
#define MFP_H

#include "Network.h"
#include "Modem.h"
#include "Scanner.h"
#include "PrintEngine.h"
#include "JobController.h"
#include "ControlPanel.h"
#include "Connection.h"
#include "InputDevice.h"
#include "JobController.h"
#include "MFP.h"

/*
The embodiment of the entire MFP.
*/
class MFP
{
public:
	static MFP& getInstance();	// doing the Singleton dance
	virtual ~MFP() throw();

	/*
	Functions for feeding the MFP input.
	*/
	Connection* openConnection(DeviceTypes::DEVICE_TYPE which);

	void pressScanButton();
	void pressCopyButton(int numCopies, bool collate);
	void pressFaxButton();

	void runJobs();

	
	// TODO: Bring out some basic control panel stuff here.
	// TODO: probably some kind of "process a job, yo" function.

private:
	Network network;
	Scanner scanner;
	Modem modem;
	PrintEngine engine;
	ControlPanel panel;
	PaperTray tray;
	JobController jobController;

	MFP();
	MFP(const MFP&);
	MFP& operator=(const MFP&);
};

#endif	//MFP_H
