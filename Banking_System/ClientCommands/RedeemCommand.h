#pragma once
#include "../Command.h"
class RedeemCommand : public Command
{
public:

	void execute(BankSystem* app) override;
};

