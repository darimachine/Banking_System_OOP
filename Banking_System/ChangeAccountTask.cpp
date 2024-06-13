#include "ChangeAccountTask.h"



ChangeAccountTask::ChangeAccountTask(const MyString& type, const MyString& newBank, Client& client, Bill& billToChange)
	:Task(type,client),newBank(newBank),billToValidate(billToChange)
{
}

const MyString& ChangeAccountTask::getNewBank() const
{
	return newBank;
}

const Bill& ChangeAccountTask::getBill() const
{
	return billToValidate;
}


