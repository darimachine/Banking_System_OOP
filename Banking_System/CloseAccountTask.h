#pragma once
#include "Task.h"
#include "Bill.h"
class CloseAccountTask : public Task
{
	Bill& bankAccount;
public:
	CloseAccountTask(Client& client, Bill& account);
	// Inherited via Task
	void viewDetails() const override;

	void viewMessage() const override;

	Task* clone() const override;

};

