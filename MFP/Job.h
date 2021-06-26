
#ifndef JOB_H
#define JOB_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "DeviceTypes.h"

/**
Job associates document data with job settings, and is
managed/scheduled by an associated JobController.
*/
class Job
{
public:
	// Constructor
	Job(class JobController& jc);
	
	// Destructor
	virtual ~Job() throw();

	// Getters
	std::stringstream& getDocStream();
	DeviceTypes::DEVICE_TYPE getOutputDeviceType() const;
	DeviceTypes::DEVICE_TYPE getInputDeviceType() const;	
	bool getCollate() const;
	unsigned int getNumPages() const;
	unsigned int getNumCopies() const;
	std::string getFaxNum() const;
	std::string getPage(unsigned int pageNum) const;	

	// Setters
	void setInputDeviceType(DeviceTypes::DEVICE_TYPE);
	void setOutputDeviceType(DeviceTypes::DEVICE_TYPE);
	void setCollate(bool coll);
	void setCopies(unsigned int c);
	void setFaxNum(std::string num);

	// Public functions	
	void submit();
private:
	// Private function
	void setPages(unsigned int p);
	std::vector<std::string> splitDocPages(std::stringstream &doc);

	// Private variables
	JobController &jobCtrl; // Associated JobController
	std::stringstream docStream; // Document content
	DeviceTypes::DEVICE_TYPE inputDeviceType; // Input device, source of document
	DeviceTypes::DEVICE_TYPE outputDeviceType; // Output device, destination of document
	bool collated; // Collation value, for printing
	unsigned int numPages; // 
	unsigned int numCopies;
	std::string faxNum;
	std::vector<std::string> pages;
};
#endif //JOB_H