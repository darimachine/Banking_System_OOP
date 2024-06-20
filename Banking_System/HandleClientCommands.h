#pragma once
#include "Command.h"
class HandleClientCommands : public Command
{

public:

	void execute(BankSystem* app) override;
};

