#pragma once
#include "Command.h"
class ValidateTaskCommand:public Command
{
public:

	void execute(BankSystem* app) override;
};

