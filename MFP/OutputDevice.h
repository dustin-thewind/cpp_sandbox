/*
Team Abstract Giraffe All-in-One Printer Model
CSC300
July 2015
*/

#ifndef OUTPUTDEVICE_H
#define OUTPUTDEVICE_H

#include "Job.h"

/*
Output devices derive a common interface from this.
*/
class OutputDevice
{
public:
	virtual void StartJob(Job *pJob) = 0;
};

#endif //OUTPUTDEVICE_H
