#pragma once
#include "Task.h"
#include "../Bill.h"
class CloseAccountTask : public Task
{
	MyString bank;
	unsigned accountID;

public:
	CloseAccountTask(Client& client, const MyString& bank,unsigned id);
	// Inherited via Task
	void viewDetails() const override;

	const MyString& getCurrentBankName() const;
	unsigned getAccountId() const;

	void viewMessage() const override;
	Task* finish() override;
	Task* clone() const override;


	// Inherited via Task
	const MyString& getClientName() const override;

};

