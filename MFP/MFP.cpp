/*
Team Abstract Giraffe All-in-One Printer Model
CSC300
July 2015

Blame for this code lies squarely on Scott Chicoine
*/

#include "MFP.h"

MFP::MFP() :
	network(jobController,panel),
	scanner(jobController),
	modem(jobController,panel),
	engine(&tray,&panel),
	jobController(engine, modem, network),
	panel(scanner)
{

}

MFP::~MFP() throw()
{

}

Connection* MFP::openConnection(DeviceTypes::DEVICE_TYPE which)
{
	switch (which)
	{
	case DeviceTypes::SCANNER:
		return scanner.openConnection();
	case DeviceTypes::NETWORK:
		return network.openConnection();
	case DeviceTypes::MODEM:
		return modem.openConnection();
	}
	return NULL;
}

MFP& MFP::getInstance()
{
	static MFP instance;	// the one and only MFP instance
	return instance;
}

void MFP::runJobs()
{
	jobController.runJobs();
}

void MFP::pressScanButton()
{
	panel.pressScanButton();
}

void MFP::pressCopyButton(int numCopies, bool collate)
{
	panel.pressCopyButton(numCopies, collate);
}

void MFP::pressFaxButton()
{
	panel.pressFaxButton();
}
