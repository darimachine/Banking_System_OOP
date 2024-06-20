#pragma once
#include "../Command.h"
class HandleNoneCommand : public Command
{
public:
	// Inherited via Command
	void execute(BankSystem* app) override;
};

