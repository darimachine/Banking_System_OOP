#pragma once
#include "../Command.h"
class LogOutCommand : public Command
{
public:
	// Inherited via Command
	void execute(BankSystem* app) override;
};

