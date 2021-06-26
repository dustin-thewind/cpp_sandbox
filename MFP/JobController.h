/*
Team Abstract Giraffe All-in-One Printer Model
CSC300
July 2015
*/

#ifndef JOBCONTROLLER_H
#define JOBCONTROLLER_H

#include "Connection.h"
#include <queue>
#include "Job.h"
#include "OutputDevice.h"
#include "Exceptions.h"

/*
JobController maintains a queue of jobs.
<br>
addJobToQueue(Job *pJob)
processNextJob()
runJobs()
*/
class JobController
{
public:
	/**
	Constructor for the job controller
	@param p the ptiner output device
	@param m the modem output device
	@param n the network output device
	*/
	JobController(OutputDevice &p, OutputDevice &m, OutputDevice &n);

	/**
	Destructor - does nothing
	*/
	virtual ~JobController() throw();

	/**
	Called by input devices when they have a complete job ready to print
	@param *pJob a pointer to a job
	*/
	void addJobToQueue(Job *pJob);

	/**
	Process the next job in the queue
	*/
	void processNextJob();

	/**
	Run the jobs in the queue
	*/
	void runJobs();
	
private:
	/*
	Received Jobs are kept here until it's their turn to print
	*/
	std::queue<Job*> jobQueue;

	/*
	The output devices
	*/
	OutputDevice &printEngine;
	OutputDevice &modem;
	OutputDevice &network;
};

#endif //JOBCONTROLLER_H
