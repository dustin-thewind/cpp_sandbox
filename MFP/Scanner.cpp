/*
Team Abstract Giraffe All-in-One Printer Model
CSC300
July 2015
*/

#include "Scanner.h"
#include "Job.h"
#include "DeviceTypes.h"

Scanner::Scanner( JobController &jc ) :
	InputDevice(jc), jobCtrl(jc)
{	
}

Scanner::~Scanner() throw()
{
	
}

Connection *Scanner::openConnection()
{
	Connection *pCon = InputDevice::openConnection();
	if (pCon)
	{
		Job *pJob = pCon->getJob();
		pJob->setInputDeviceType(DeviceTypes::SCANNER);
		/*
		TODO: Any input device-specific job settings can be made here.
		*/
	}
	return pCon;

}



//how many pages loaded in it, creates a job and writes what page 1 to the scanner, page 2 to the scanner, etc, close
// put \f in the file then it is a different pages

