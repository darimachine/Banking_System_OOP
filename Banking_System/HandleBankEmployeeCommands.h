#pragma once
#include "Command.h"
class HandleBankEmployeeCommands : public Command
{
	// Inherited via Command
	void execute(BankSystem* app) override;
};

