#pragma once
#include "../Command.h"
class CreateBankCommand: public Command
{
public:

	void execute(BankSystem* app) override;
};

