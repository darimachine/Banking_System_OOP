#pragma once
#include "Command.h"
class ViewTaskCommand : public Command
{
	// Inherited via Command
	void execute(BankSystem* app) override;
};

