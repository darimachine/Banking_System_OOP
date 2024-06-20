#pragma once
#include <iostream>
#include "BankSystem.h"
class Command
{
public:
	virtual ~Command() = default;
	virtual void execute(BankSystem* app) = 0;
};