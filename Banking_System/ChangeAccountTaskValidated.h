#pragma once
#include "ChangeAccountTask.h"
class ChangeAccountTaskValidated : public ChangeAccountTask 
{
	
public:
	ChangeAccountTaskValidated(const MyString& newBank, Client& client, Bill& billToChange);

	// Inherited via ChangeAccountTask
	void viewDetails() const override;
	void viewMessage() const override;
};

