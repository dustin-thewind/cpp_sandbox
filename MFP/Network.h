/*
Team Abstract Giraffe All-in-One Printer Model
CSC300
July 2015
*/

#ifndef NETWORK_H
#define NETWORK_H

#include "InputDevice.h"
#include "OutputDevice.h"
#include "ControlPanel.h"

class Network : public InputDevice, public OutputDevice
{
public:
	Network( JobController&, ControlPanel& );
	virtual ~Network() throw();

	Connection *Network::openConnection();
	void StartJob(Job *pJob);
private:
	ControlPanel &panel;
};

#endif //NETWORK_H
