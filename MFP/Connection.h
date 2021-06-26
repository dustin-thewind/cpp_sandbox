/*
Team Abstract Giraffe All-in-One Printer Model
CSC300
July 2015

Scott Chicoine is responsible for this mess.
*/

#ifndef CONNECTION_H
#define CONNECTION_H

#include <string>
#include "InputDevice.h"
#include "Job.h"

/*
Connection represents a temporary connection for input from the outside world.
A Connection may be used to feed any of the input devices some document data.
*/
class Connection
{
	friend class InputDevice;
public:
	void write(const std::string& data);
	void close();
	Job *getJob();

private:
	// Cannot construct directly.  Must use InputDevice::openConnection to do so.
	Connection(InputDevice& device, Job *pJob);

	InputDevice &device;
	Job *pJob;
	bool isClosed;

	// hide these
	Connection(const Connection&);
	virtual ~Connection() throw();
	Connection& operator=(const Connection&);
};

#endif	//CONNECTION_H
