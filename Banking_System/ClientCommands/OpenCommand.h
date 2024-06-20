#pragma once
#include "../Command.h"
class OpenCommand : public Command
{
public:

	void execute(BankSystem* app) override;
};

