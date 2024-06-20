#pragma once
#include "Task.h" 
#include "../Bill.h"
#include "../Utilities/IDGenerateParse.h"
class ChangeAccountTask : public Task
{
protected:
	MyString newBank;
	MyString oldBank;
	unsigned accountID;
public:
	ChangeAccountTask(const MyString& type ,const MyString& newBank, Client& client, const MyString& oldBank,unsigned accountID);

	//const MyString& getNewBank() const;

	// Inherited via Task
	const MyString& getCurrentBankName() const override;
	unsigned getAccountId() const override;
	void viewDetails() const = 0;
	void viewMessage() const = 0;
	virtual Task* finish() = 0;
	Task* clone() const = 0;


	
};
