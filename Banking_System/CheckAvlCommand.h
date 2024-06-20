#pragma once
#include "Command.h"
class CheckAvlCommand : public Command
{
public:

	void execute(BankSystem* app) override;
};

