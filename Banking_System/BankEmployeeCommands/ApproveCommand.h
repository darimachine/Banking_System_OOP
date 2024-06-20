#pragma once
#include "../Command.h"
class ApproveCommand: public Command
{
public:

	void execute(BankSystem* app) override;
};

