#pragma once
#include "../Command.h"
class ShowTasksCommand: public Command
{
public:

	void execute(BankSystem* app) override;
};

