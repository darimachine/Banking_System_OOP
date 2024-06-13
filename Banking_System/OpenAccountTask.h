#pragma once
#include "Task.h"
class OpenAccountTask : Task
{
	
public:
	OpenAccountTask(Client& clientInfo);
	void viewDetails() const override;

	// Inherited via Task
	void viewMessage() const override;
};

