#pragma once
#include "../Command.h"
class DisapproveCommand : public Command
{
public:

	void execute(BankSystem* app) override;
};

