/*
Team Abstract Giraffe All-in-One Printer Model
CSC300
July 2015
*/

#include "MFP.h"
using namespace std;

int main(int argc, char *argv[])
{
	MFP &mfp = MFP::getInstance();
	string pressEnter;

	/*
	Use Case 1:  Send a FAX from the scanner.
	*/
	cout << "Use Case 1:  Send a FAX from the scanner.\n";
	mfp.pressFaxButton();
	mfp.runJobs();

	cout << "Press Enter to see next example\n\n";
	getline(cin, pressEnter);
	/*
	Use Case 1.1: Send a fax from a remote network user
	*/
	cout << "Use Case 1.1: Send a fax from a remote network user\n";
	Connection *pCon = mfp.openConnection(DeviceTypes::NETWORK);
	pCon->getJob()->setOutputDeviceType(DeviceTypes::MODEM);
	pCon->write("First page of a network-received FAX.\n");
	pCon->write("\fSecond page of network-received FAX.\n");
	pCon->close();	// pCon now invalid, deleted

	mfp.runJobs();

	cout << "Press Enter to see next example\n\n";
	getline(cin, pressEnter);
	/*
	Use Case 2: Receive and print a FAX
	*/
	cout << "Use Case 2: Receive and print a FAX\n";
	pCon = mfp.openConnection(DeviceTypes::MODEM);
	pCon->getJob()->setOutputDeviceType(DeviceTypes::PRINTER);
	pCon->write("First page of a received FAX.\n");
	pCon->write("\fSecond page of received FAX.\n");
	pCon->close();	// pCon now invalid, deleted

	mfp.runJobs();

	cout << "Press Enter to see next example\n\n";
	getline(cin, pressEnter);
	/*
	Use Case 3: Scan a document and send to remote user over network
	*/
	cout << "Use Case 3: Scan a document and send to remote user over network\n";
	mfp.pressScanButton();
	//mfp.runJobs();

	/*
	Use Case 4: Copy Document: Scan and print
	*/
	cout << "Use Case 4: Copy Document: Scan and print 3 copies NOT collated\n"; 
	mfp.pressCopyButton(3,false);
	mfp.runJobs();

	cout << "Press Enter to see next example\n\n";
	getline(cin, pressEnter);
	/*
	Use Case 5: Print a document sent by a remote user over the network.
	Simulate the opening of a network connection and 
	submitting a 2-page document to be printed.
	*/
	cout << "Use Case 5: Print a document sent by a remote user over the network.\n";
	pCon = mfp.openConnection(DeviceTypes::NETWORK);
	pCon->getJob()->setOutputDeviceType(DeviceTypes::PRINTER);
	pCon->write("First page of a print job from the network.\n");
	pCon->write("\fSecond page!\n");
	pCon->close();	// pCon now invalid, deleted

	mfp.runJobs();

	cout << "Press Enter to see next example\n\n";
	getline(cin, pressEnter);
	/*
	Another remote print job, show how copies and collate work
	*/
	cout << "Another remote print job, show how copies (2) and collate(true) work.\n";
	pCon = mfp.openConnection(DeviceTypes::NETWORK);
	pCon->getJob()->setOutputDeviceType(DeviceTypes::PRINTER);
	pCon->getJob()->setCopies(2);
	pCon->getJob()->setCollate(true);
	pCon->write("First page of a print job from the network.\n");
	pCon->write("\fSecond page!\n");
	pCon->write("\fThird print page!\n");
	pCon->close();	// pCon now invalid, deleted

	mfp.runJobs();
}
