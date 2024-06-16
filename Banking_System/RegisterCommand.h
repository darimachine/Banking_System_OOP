#pragma once
#include "Command.h"
class RegisterCommand : public Command
{
	// Inherited via Command
	void execute(BankSystem* app) override;
};

