#pragma once
#include "Command.h"
class CreateBankCommand: public Command
{
	// Inherited via Command
	void execute(BankSystem* app) override;
};

