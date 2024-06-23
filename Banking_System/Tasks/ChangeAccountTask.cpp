#include "ChangeAccountTask.h"



ChangeAccountTask::ChangeAccountTask(const MyString& type, const MyString& newBank, Client& client, const MyString& oldBank, unsigned accountID)
	:Task(type,client),newBank(newBank),oldBank(oldBank),accountID(accountID)
{
}

//const MyString& ChangeAccountTask::getNewBank() const
//{
//	return newBank;
//}

const MyString& ChangeAccountTask::getCurrentBankName() const
{
	return oldBank;
	// TODO: insert return statement here
}

const MyString& ChangeAccountTask::getNewBankName() const
{
	return newBank;
}

unsigned ChangeAccountTask::getAccountId() const
{
	return accountID;
}



