/*
Team Abstract Giraffe All-in-One Printer Model
CSC300
July 2015
*/

#include "PrintEngine.h"

PrintEngine::PrintEngine( PaperTray* pT, ControlPanel* cP)
{
	m_paperTray = pT;
	m_controlPanel = cP;
}

PrintEngine::~PrintEngine() throw()
{}

// Implements OutputDevice
void PrintEngine::StartJob(Job *pJob)
{
	// set up a page order vector.
	std::vector<int> pageOrder;
	if (pJob->getCollate())
	{
		for (unsigned int i = 0; i < pJob->getNumCopies(); i++)
			for (unsigned int j = 0; j < pJob->getNumPages(); j++)
				pageOrder.push_back(j);
	}
	else
	{
		for (unsigned int i = 0; i < pJob->getNumPages(); i++)
			for (unsigned int j = 0; j < pJob->getNumCopies(); j++)
				pageOrder.push_back(i);
	}

	//print the pages
	unsigned int pos = 0;
	while (pos < pageOrder.size())
	{
		if (m_paperTray->hasPaper())
		{
			m_paperTray->usePage(); 
			std::cout << "Printer: " << pJob->getPage(pageOrder[pos]);
			++pos;
		}
		else
		{
			m_controlPanel->errorMessage("The paper tray is out of paper.\n");
			// This is faking user adding 10 to 20 sheets of paper and continuing
			m_paperTray->addPaper(rand() % 10 + 11);
			m_controlPanel->errorMessage("Resuming Printing.\n");
		}
	}
}





