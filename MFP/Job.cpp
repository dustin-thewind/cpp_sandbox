/**
Team Abstract Giraffe All-in-One Printer Model
CSC300
July 2015
Job Object Definitions
*/
#include "Job.h"
#include "JobController.h"

/**
Constructor
Creates a Job object associated with the passed JobController reference.
Instantiates variables to default values, to be overridden through mutators.
Copies passed document stream into an internal document stream.
Calls methods to create pages of content from internal document stream, and sets number of pages.
@param &jc - reference to the associated JobController
@param &doc - reference to the document stream being associated with the job
*/
Job::Job(JobController &jc)
	: jobCtrl(jc),
	inputDeviceType(DeviceTypes::INVALID),
	outputDeviceType(DeviceTypes::INVALID)
{
	collated = false;
	numCopies = 1;
	numPages = 0;
	faxNum = "000-000-0000";	
}

/**
Destructor
*/
Job::~Job() throw() {}

/**
Get job document stream.
@return - A reference to the job document stream
*/
std::stringstream& Job::getDocStream()
{
	return docStream;
}

/**
Get job output device type.
@return - The output device type
*/
DeviceTypes::DEVICE_TYPE Job::getOutputDeviceType() const
{
	return outputDeviceType;
}

/**
Get job input device type.
@return - The input device type
*/
DeviceTypes::DEVICE_TYPE Job::getInputDeviceType() const
{
	return inputDeviceType;
}

/**
Get collation value, for printing.
@return - true if collated, false if not collated
*/
bool Job::getCollate() const
{
	if (collated)
		return true;
	else
		return false;
}

/**
Get number of pages in job document.
@return - The number of pages, set during constructor's call to splitDocPages
*/
unsigned int Job::getNumPages() const
{
	return numPages;
}

/**
Get number of copies, for printing.
@return - The number of copies
*/
unsigned int Job::getNumCopies() const
{
	return numCopies;
}

/**
Get fax number.
@return - A string containing the fax number
*/
std::string Job::getFaxNum() const
{
	return faxNum;
}

/**
Get a page from the job document.
@pageNum - page requested
@return - A string containing the requested page content 
*/
std::string Job::getPage(unsigned int pageNum) const
{
	bool outOfRange = false;
	bool invalidInput = false;
	unsigned int p = pageNum;

	if (p > pages.size())
		outOfRange = true;

	while (outOfRange)
	{
		std::cout << "Requested page out of range!" << std::endl;
		std::cout << "Document has " << getNumPages() << " pages, request a page in range: ";
		std::cin >> p;

		if (std::cin.fail())
			invalidInput = true;
		while (invalidInput)
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Invalid input, enter a positive integer: ";
			std::cin >> p;
			if (!std::cin.fail())
				invalidInput = false;
		}
	}
	
	return pages[p];
}

/**
Set input device.
@param type - type of input device, valid types defined in DeviceTypes
*/
void Job::setInputDeviceType(DeviceTypes::DEVICE_TYPE type)
{
	inputDeviceType = type;
}

/**
Set output device.
@param type - type of output device, valid types defined in DeviceTypes
*/
void Job::setOutputDeviceType(DeviceTypes::DEVICE_TYPE type)
{
	outputDeviceType = type;
}

/**
Set collation value.
@param coll - bool, true if collated, false if not collated
*/
void Job::setCollate(bool coll)
{
	collated = coll;
}

/**
Set number of copies.
@param c - number of copies
*/
void Job::setCopies(unsigned int c)
{
	numCopies = c;
}

/**
Set fax number.
@param num - A string representing the fax number
*/
void Job::setFaxNum(std::string num)
{
	faxNum = num;
}

/**
Submit a ready Job to the associated JobController.
*/
void Job::submit()
{
	pages = splitDocPages(docStream);
	
	jobCtrl.addJobToQueue(this);
}

/**
Set number of pages.
Private, only called by splitDocPages method.
@param p - number of pages
*/
void Job::setPages(unsigned int p)
{
	numPages = p;
}

/**
Split document stream into pages and stores them as strings in a vector.
Private, only called by constructor.
@param &doc - reference to document stream
@return - returns a vector of strings representing pages
*/
std::vector<std::string> Job::splitDocPages(std::stringstream &doc)
{
	std::string temp;
	std::vector<std::string> pages;
	while (getline(doc, temp, '\f'))
	{
		pages.push_back(temp);
	}
	Job::setPages(pages.size());
	return pages;
}