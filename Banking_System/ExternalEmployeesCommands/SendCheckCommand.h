#pragma once
#include "../Command.h"
class SendCheckCommand: public Command
{
public:

	void execute(BankSystem* app) override;
};

