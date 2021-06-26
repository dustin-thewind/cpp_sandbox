

#include <iostream>
#include "InputDevice.h"
#include "MFP.h"

using namespace std;

InputDevice::InputDevice( JobController &jobCtrl ) :
	jobCtrl(jobCtrl)
{
}

InputDevice::~InputDevice() throw()
{
}

/*
Create a new connection.  May be virtualized by the actual input device
in order to tag the job with device-specific stuff first.
*/
Connection* InputDevice::openConnection()
{
	try
	{
		Job *pJob = new Job(jobCtrl);
		return new Connection(*this, pJob);
	}
	catch (...)
	{
		cerr << "ERROR: Failed to create new connection!\n";
	}
	return NULL;
}