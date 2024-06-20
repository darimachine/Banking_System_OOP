#include "ChangeAccountTask.h"



ChangeAccountTask::ChangeAccountTask(const MyString& type, const MyString& newBank, Client& client, const MyString& oldBank, unsigned accountID)
	:Task(type,client),newBank(newBank),oldBank(oldBank),accountID(accountID)
{
}

const MyString& ChangeAccountTask::getNewBank() const
{
	return newBank;
}

const MyString& ChangeAccountTask::getBankNameForChange() const
{
	return oldBank;
	// TODO: insert return statement here
}

unsigned ChangeAccountTask::getBankNameIdChange() const
{
	return accountID;
}



