#pragma once
#include "ChangeAccountTask.h"

class ChangeAccountTaskValidated : public ChangeAccountTask 
{
	
public:
	ChangeAccountTaskValidated(const MyString& newBank, Client& client, const MyString& oldBank, unsigned accountID);

	// Inherited via ChangeAccountTask
	void viewDetails() const override;
	void viewMessage() const override;
	Task* clone() const override;

	// Inherited via ChangeAccountTask
	Task* finish() override;

	// Inherited via ChangeAccountTask
	const MyString& getClientName() const override;
};

