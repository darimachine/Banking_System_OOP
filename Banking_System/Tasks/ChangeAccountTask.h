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
	const MyString& getNewBankName() const override;
	unsigned getAccountId() const override;
	virtual void viewDetails() const = 0;
	virtual void viewMessage() const = 0;
	virtual Task* finish() = 0;
	virtual Task* clone() const = 0;
	virtual ~ChangeAccountTask() = default;

	
};

