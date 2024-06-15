#pragma once
#include "Task.h"
class OpenAccountTask : public Task
{
	MyString bankName;
public:
	OpenAccountTask(const MyString& bankName,Client& clientInfo);
	void viewDetails() const override;

	// Inherited via Task
	void viewMessage() const override;

	// Inherited via Task
	Task* clone() const override;

	// Inherited via Task
	virtual Task* finish();
};

