#pragma once
#include "ChangeAccountTask.h"
class Client;
class ChangeAccountTaskApproved : public ChangeAccountTask
{
public:
	ChangeAccountTaskApproved(const MyString& newBank, Client& client, Bill& billToChange);

	// Inherited via ChangeAccountTask
	void viewDetails() const override;
	void viewMessage() const override;

	
	Task* clone() const override;
};

