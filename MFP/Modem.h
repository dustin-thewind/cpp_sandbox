

#ifndef MODEM_H
#define MODEM_H

#include "OutputDevice.h"
#include "InputDevice.h"
#include "ControlPanel.h"

class Modem : public OutputDevice, public InputDevice
{
public:
	Modem(JobController&, ControlPanel&);
	virtual ~Modem() throw();

	// Implements custom openConnection
	class Connection* openConnection();

	// implements OutputDevice
	void StartJob(Job *pJob);

private:
	ControlPanel &panel;
};

#endif //MODEM_H