#pragma once
#include "Command.h"
class SendCheckCommand: public Command
{
	// Inherited via Command
	void execute(BankSystem* app) override;
};

