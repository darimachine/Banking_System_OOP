#pragma once
#include "Command.h"
class LoginCommand:public Command
{
public:

	void execute(BankSystem* app) override;
};

