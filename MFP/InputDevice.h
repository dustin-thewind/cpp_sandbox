

#ifndef INPUTDEVICE_H
#define INPUTDEVICE_H

/*
InputDevice provides common interface and functionality used
by all input devices, like the scanner, the modem, and the network devices.
*/
class InputDevice
{
	friend class Connection;
public:
	InputDevice( class JobController& );
	virtual ~InputDevice() throw();

	// Here's how you get a Connection instance...
	virtual class Connection* openConnection();

private:
	class JobController &jobCtrl;
	// TODO could track open connections here.... do we need to?
};

#endif	//INPUTDEVICE_H
