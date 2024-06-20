#pragma once
#include "../Command.h"
class RegisterCommand : public Command
{
public:

	void execute(BankSystem* app) override;
};

