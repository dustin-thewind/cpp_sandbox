/*
Team Abstract Giraffe All-in-One Printer Model
CSC300
July 2015

Some say he once coded a tic-tac-toe game with nothing more than
a typewriter and a set of Tinkertoys.  All we know is that we call him...
Scott Chicoine.
*/

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
