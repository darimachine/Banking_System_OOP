#pragma once
#include "Task.h" 
#include "Bill.h"
class ChangeAccountTask : public Task
{
protected:
	MyString newBank;
	Bill& billToValidate;
public:
	ChangeAccountTask(const MyString& type ,const MyString& newBank, Client& client, Bill& billToChange);

	// Inherited via Task
	void viewDetails() const =0;
	void viewMessage() const =0;

	const MyString& getNewBank() const;
	const Bill& getBill() const;
};

