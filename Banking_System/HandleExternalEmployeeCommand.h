#pragma once
#include "Command.h"
class HandleExternalEmployeeCommand : public Command
{
public:

	void execute(BankSystem* app) override;
};

