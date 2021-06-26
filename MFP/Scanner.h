

#ifndef SCANNER_H
#define SCANNER_H

#include "InputDevice.h"
#include "Exceptions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Connection.h"

/*
Scanner is strictly an input device.
*/
class Scanner : public InputDevice
{
public:
	Scanner( JobController &jobCtrl );
	virtual ~Scanner() throw();

	/*
	May throw error NoDocument exception
	"scans" a file and stores it in the pointer d_scan
	*/
	Connection *Scanner::openConnection();

private:
	//Document* d_scan;
	JobController &jobCtrl;
};

///createa a job

#endif //SCANNER_H
