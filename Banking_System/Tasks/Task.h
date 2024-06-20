#pragma once
#include "../Utilities/MyString.h"
class Bill;
class Client;
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
	//Task(const MyString& type, Client& clientInfo);
	virtual void viewDetails() const = 0;
	virtual void viewMessage() const = 0;
	virtual Task* clone() const = 0;
	
	const MyString& getType() const;
	virtual const MyString& getCurrentBankName() const;
	virtual unsigned getAccountId() const;
	virtual Task* finish() = 0;
	Client& getClient();
	virtual ~Task() = default;
};

