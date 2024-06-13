#include "OpenAccountTask.h"
using std::cout;
using std::endl;
OpenAccountTask::OpenAccountTask(Client& clientInfo)
	:Task("Open",clientInfo)
{
}

void OpenAccountTask::viewDetails() const
{
	cout << type << "request from:\n";
	cout << "Name: " << client.getName() << endl;
	cout << "EGN: " << client.getEGN() << endl;
	cout << "Age: " << client.getAge() << endl;
}

void OpenAccountTask::viewMessage() const 
{
	cout << type << " - " << client.getName() << "wants to create an account.\n";
}
