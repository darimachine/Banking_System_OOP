#pragma once
#include "Command.h"
class ValidateTaskCommand:public Command
{
	// Inherited via Command
	void execute(BankSystem* app) override;
};

