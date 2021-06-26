

#include <string>
#include <iostream>
#include <sstream>
#include "Modem.h"
#include "Connection.h"

using namespace std;

Modem::Modem( JobController &jc, ControlPanel &panel ):
	InputDevice(jc),
	panel(panel)
{
}

Modem::~Modem() throw()
{
}

Connection *Modem::openConnection()
{
	Connection *pCon = InputDevice::openConnection();
	if (pCon)
	{
		Job *pJob = pCon->getJob();
		pJob->setInputDeviceType(DeviceTypes::MODEM);
		/*
		TODO: Any input device-specific job settings can be made here.
		*/
	}
	return pCon;
}

// Implements OutputDevice
void Modem::StartJob(Job *pJob)
{
	/*
	FAX is simply sent in normal page order, ignoring copies/collation
	*/
	cout << "FAX: Start sending job.\n";
	unsigned int iPage = 0;
	while (iPage < pJob->getNumPages())
	{
		stringstream msg;
		msg << "Faxing page " << iPage + 1 << " of " << pJob->getNumPages() << "\n";
		panel.errorMessage(msg.str());
		cout << "FAX: page " << iPage + 1 << ": " << pJob->getPage(iPage) << "\n";
		iPage++;
	}
	if (0 == iPage)
		cout << "FAX: Job has no pages!\n";
	else
		cout << "FAX: Sent " << iPage << " pages.\n";
	cout << "FAX: Job complete.\n";
}
