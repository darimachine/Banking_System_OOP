#pragma once
#include "Command.h"
class ChangeCommand : public Command
{
public:

	void execute(BankSystem* app) override;
};

