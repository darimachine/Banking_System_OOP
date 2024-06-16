#pragma once
#include "Command.h"
class HandleExternalEmployeeCommand : public Command
{
	// Inherited via Command
	void execute(BankSystem* app) override;
};

