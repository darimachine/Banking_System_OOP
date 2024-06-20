#pragma once
#include "../Command.h"
class MessagesCommand : public Command
{
public:

	void execute(BankSystem* app) override;
};

