#pragma once
#include "Command.h"
class LoginCommand:public Command
{
	// Inherited via Command
	void execute(BankSystem* app) override;
};

