#include "OpenAccountTask.h"
#include "Client.h"
using std::cout;
using std::endl;
OpenAccountTask::OpenAccountTask(const MyString& bankName,Client& clientInfo)
	:Task("Open",clientInfo), bankName(bankName)
{
}

void OpenAccountTask::viewDetails() const
{
	cout << type << " request from:\n";
	cout << "Name: " << client.getName() << endl;
	cout << "EGN: " << client.getEGN() << endl;
	cout << "Age: " << client.getAge() << endl;
}

void OpenAccountTask::viewMessage() const 
{
	cout << type << " - " << client.getName() << " wants to create an account.\n";
}

Task* OpenAccountTask::clone() const
{
	return new OpenAccountTask(*this);
}
