
#include "Connection.h"

using namespace std;

Connection::Connection(InputDevice &device, Job *pJob) :
	device(device),
	pJob(pJob),
	isClosed(false)
{
}

Connection::~Connection() throw()
{
}

void Connection::write(const string& data)
{
	if (!isClosed)
		pJob->getDocStream() << data;
}

void Connection::close()
{
	if (!isClosed)
	{
		isClosed = true;
		pJob->getDocStream().seekg(0);
		pJob->submit();
	}
	delete this;
}

Job* Connection::getJob()
{
	return pJob;
}
