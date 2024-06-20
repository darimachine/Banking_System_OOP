#pragma once
#include "../Command.h"
class ListCommand : public Command
{
public:

	void execute(BankSystem* app) override;
};

