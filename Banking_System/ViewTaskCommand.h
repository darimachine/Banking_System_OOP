#pragma once
#include "Command.h"
class ViewTaskCommand : public Command
{
public:

	void execute(BankSystem* app) override;
};

