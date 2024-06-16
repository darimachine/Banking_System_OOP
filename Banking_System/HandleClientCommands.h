#pragma once
#include "Command.h"
class HandleClientCommands : public Command
{
	// Inherited via Command
	void execute(BankSystem* app) override;
};

