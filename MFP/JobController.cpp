/*
Team Abstract Giraffe All-in-One Printer Model
CSC300
July 2015
*/

#include "JobController.h"

JobController::JobController(OutputDevice &p, OutputDevice &m, OutputDevice &n) :
		printEngine(p), modem(m), network(n)
{}

JobController::~JobController() throw()
{}

void JobController::addJobToQueue(Job *pJob)
{
	jobQueue.push(pJob);
	/*
	TODO: do we need to notify anybody?
	*/
}

void JobController::processNextJob()
{
	// be sure that there is a job
	if (jobQueue.size() > 0)
	{
		// get the job on the front of the queue
		Job* currentJob = jobQueue.front();

		// activate the apropriate output engine
		switch (currentJob->getOutputDeviceType())
		{
		case DeviceTypes::PRINTER: printEngine.StartJob(currentJob);
			break;
		case DeviceTypes::NETWORK: network.StartJob(currentJob);
			break;
		case DeviceTypes::MODEM: modem.StartJob(currentJob);
			break;
		default:
			throw InvalidOutputDevice("Invalid Output Devide requested");
			break;
		}

		delete currentJob;
		jobQueue.pop();
	}

}

void JobController::runJobs()
{
	while (jobQueue.size() > 0)
		processNextJob();
}
