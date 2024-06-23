#include "BankEmployee.h"
#include "Client.h"
#include "../TaskFileFactory.h"
using std::cout;
using std::endl;



bool BankEmployee::isValidTaskID(unsigned taskID) const
{
	taskID--;
	if (taskID<0 || taskID>tasks.getSize())
	{
		return false;
	}
	return true;
}

BankEmployee::BankEmployee(const MyString& name, const MyString& egn, unsigned age, const MyString& password, const MyString& bankAssociated)
	:User(name,egn,age,password),bankAssociated(bankAssociated)
{
}

void BankEmployee::addTask(Task* task)
{
	tasks.pushBack(task);
}
void BankEmployee::showTasks() const
{
    unsigned size = tasks.getSize();
	for (int i = 0; i < size; i++)
	{
		cout << "[" << i + 1 << "]  ";
		tasks[i]->viewMessage();
		cout << endl;
	}
}

void BankEmployee::view(unsigned taskID) const
{
	if (!isValidTaskID(taskID))
	{
		throw std::invalid_argument("Task ID is Invalid");
	}
	tasks[taskID-1]->viewDetails();
}

void BankEmployee::removeTask(unsigned id)
{
	tasks.popAt(id);
}

unsigned BankEmployee::getTaskCount() const {
	return tasks.getSize();
}

void BankEmployee::disapprove(unsigned taskID, const MyString& message)
{
	if (!isValidTaskID(taskID))
	{
		throw std::invalid_argument("Task ID is Invalid");
	}
	MyString info = "Your ";
	info+=tasks[taskID - 1]->getType();
	info += " request was not approved. Reason: ";
	info += message;
	tasks[taskID - 1]->getClient().addMessage(info);
	removeTask(taskID - 1);

}
Task* BankEmployee::approve(unsigned taskID)
{
	if (!isValidTaskID(taskID))
	{
		throw std::invalid_argument("Task ID is Invalid");
	}
	Task* nextTask = tasks[taskID - 1]->finish();; // can be nullptr if is not then i must handle it outside
	
	if (tasks[taskID - 1]->getType() != "Change Not Validated")
	{
		removeTask(taskID - 1);
	}
	return nextTask;
}

Task* BankEmployee::validate(unsigned taskID)
{
	PolymorphicPtr<Task> currentTask = tasks[taskID - 1];
	if (currentTask->getType() != "Change Not Validated") {
		throw std::invalid_argument("You cannot validate this response");
	}
	MyString oldBank = currentTask->getCurrentBankName();
	unsigned accountID = currentTask->getAccountId();
	Client& currentClient = currentTask->getClient();
	removeTask(taskID - 1);
	return new ChangeAccountTaskValidated(bankAssociated, currentClient, oldBank, accountID);
}

void BankEmployee::help()
{
	std::cout << "Bank Employee commands:\n";
	std::cout << "1. tasks: Displays the tasks that need to be done. Each task has a type, name, and index.\n";
	std::cout << "2. view [task_id]: Shows all details about the task.\n";
	std::cout << "3. approve [task_id]: The employee completes the task and approves the request.\n";
	std::cout << "4. disapprove [task_id] [message]: The employee completes the task and denies the request.\n";
	std::cout << "5. validate [task_id]: The employee from the new bank makes a request to the old bank, validating whether the user has entered correct data. This validation does not go through an employee of the old bank and is returned immediately. Only Change tasks can be validated.\n";
}

const MyString& BankEmployee::getBankAssociated() const
{
	return bankAssociated;
}
void BankEmployee::saveEmployeeToFile(std::ofstream& ofs) const {
	User::saveToFile(ofs);
	bankAssociated.saveToFile(ofs);
}
void BankEmployee::readEmployeeFromFile(std::ifstream& ifs) {
	User::readFromFile(ifs);
	bankAssociated.readFromFile(ifs);
}
void BankEmployee::saveTasksToFile(std::ofstream& ofs) const {
	int taskCount = tasks.getSize();
	//ofs.write((const char*)&taskCount, sizeof(taskCount));
	for (int i = 0; i < taskCount; i++)
	{
		TaskFileFactory::saveTask(ofs, tasks[i].get());
	}
}