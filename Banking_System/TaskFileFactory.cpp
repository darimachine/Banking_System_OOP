#include "TaskFileFactory.h"

void TaskFileFactory::saveChangeTask(std::ofstream& ofs, const Task* task)
{
	saveRegularTask(ofs, task);
	unsigned accountID = task->getAccountId();
	ofs.write((const char*)&accountID, sizeof(accountID));
	MyString newBank = task->getNewBankName();
	newBank.saveToFile(ofs);
}

void TaskFileFactory::saveRegularTask(std::ofstream& ofs, const Task* task)
{
	MyString bankName = task->getCurrentBankName();
	bankName.saveToFile(ofs);
	MyString clientName = task->getClientName();
	clientName.saveToFile(ofs);
}

void TaskFileFactory::saveTask(std::ofstream& ofs, const Task * task)
{
	MyString type = task->getType();
	type.saveToFile(ofs);
	if (type == "Open")
	{
		saveRegularTask(ofs, task);
	}
	else if (type == "Close")
	{
		saveRegularTask(ofs, task);
		unsigned accountID = task->getAccountId();
		ofs.write((const char*)&accountID, sizeof(accountID));
	}
	else if (type == "Change Not Validated")
	{
		saveChangeTask(ofs, task);
	}
	else if (type == "Change Validated")
	{
		saveChangeTask(ofs, task);
	}
	else if (type == "Change Approved")
	{
		saveChangeTask(ofs, task);
	}
}
