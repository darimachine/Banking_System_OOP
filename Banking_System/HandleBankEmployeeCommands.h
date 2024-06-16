#pragma once
#include "Command.h"
class HandleBankEmployeeCommands : public Command
{
public:

	void execute(BankSystem* app) override;
};

