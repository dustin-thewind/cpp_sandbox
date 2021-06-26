

#include "ControlPanel.h"
#include "DeviceTypes.h"
#include "Connection.h"
#include "MFP.h"
#include <string>
#include <iostream>

using std::cout;

ControlPanel::ControlPanel(Scanner& sC)
	:scanner(sC)
{

}

ControlPanel::~ControlPanel() throw()
{

}

void ControlPanel::errorMessage(std::string message)
{
	cout << "Control Pannel: " << message;
}

/*
TODO: We look for things.  Things to make us go.
*/

void ControlPanel::pressFaxButton()
{
	Connection *pCon = scanner.openConnection();
	pCon->getJob()->setOutputDeviceType(DeviceTypes::MODEM);
	pCon->write("First page of a scanned FAX.\n");
	pCon->write("\fSecond page of scanned FAX.\n");
	pCon->close();	// pCon now invalid, deleted
}


void ControlPanel::pressScanButton()
{
	Connection *pCon = scanner.openConnection();
	pCon->getJob()->setOutputDeviceType(DeviceTypes::NETWORK);
	pCon->write("First page of a scanned sent to computer.\n");
	pCon->write("\fSecond page of scanned sent to computer.\n");
	pCon->close();	// pCon now invalid, deleted
}


void ControlPanel::pressCopyButton(int numCopies, bool collate)
{
	Connection *pCon = scanner.openConnection();
	pCon->getJob()->setOutputDeviceType(DeviceTypes::PRINTER);
	pCon->getJob()->setCopies(numCopies);
	pCon->getJob()->setCollate(collate);
	pCon->write("First page of a scanned sent to printer (copy).\n");
	pCon->write("\fSecond page of scanned sent to printer (copy).\n");
	pCon->close();	// pCon now invalid, deleted
}
