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

Task* OpenAccountTask::finish()
{
	unsigned id = generateUniqueNumber();
	Bill account(bankName, 0, id);
	client.addBill(account);
	MyString tempMessage = "You opened an account in ";
	tempMessage += bankName;
	tempMessage += "! Your account id is ";
	char idStr[20];
	intToStr(id, idStr);
	tempMessage += idStr;
	tempMessage += ".";
	//besen sum
	client.addMessage(tempMessage);
	return nullptr;
}
