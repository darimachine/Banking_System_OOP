#pragma once
//#include "Task.h"
#include "ChangeAccountTask.h"

class ChangeAccountTaskNoValidated : ChangeAccountTask
{
	// Inherited via Task
public:
	ChangeAccountTaskNoValidated(const MyString& newBank, Client& client, Bill& billToChange);
	void viewDetails() const override;

	// Inherited via Task
	void viewMessage() const override;
};

