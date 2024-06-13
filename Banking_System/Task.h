#pragma once
#include "MyString.h"
#include "Client.h"
class Task
{
protected:
	MyString type;
	Client& client;//!!!!!!!!! promeni konstruktor
	/*MyString clientName;
	MyString clientEgn;
	unsigned clientAge;*/

public:
	Task(const MyString& type, Client& clientInfo);
	virtual void viewDetails() const = 0;
	virtual void viewMessage() const = 0;
	const MyString& getType() const;
	Client& getClient();
};

