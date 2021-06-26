/*
Team Abstract Giraffe All-in-One Printer Model
CSC300
July 2015
*/

#include <string>
#include <iostream>
#include <sstream>
#include "Connection.h"
#include "Network.h"

using namespace std;

/*
Network takes a reference to job controller for creating jobs,
and to a control panel for displaying messages to the user.
*/
Network::Network( JobController &jc, ControlPanel &cp ) :
	InputDevice(jc), panel(cp)
{

}

Network::~Network() throw()
{

}

Connection *Network::openConnection()
{
	Connection *pCon = InputDevice::openConnection();
	if (pCon)
	{
		Job *pJob = pCon->getJob();
		pJob->setInputDeviceType(DeviceTypes::NETWORK);
		/*
		TODO: Any input device-specific job settings can be made here.
		*/
	}
	return pCon;
}

void Network::StartJob(Job *pJob)
{
	/*
	Email simply sends the entire document as a whole,
	again ignoring any job settings like copies or collation.
	*/
	cout << "Network: Start sending email.\n";
	stringstream &doc = pJob->getDocStream();
	cout << "Network: <email header goes here>\n";
	cout << "Network: <document as attachment goes here>\n";
	cout << "Network: Email complete.\n";
}