#include "BankEmployee.h"
#include "Client.h"
using std::cout;
using std::endl;



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
		cout << "[" << i + 1 << "]";
		tasks[i]->viewMessage();
		cout << endl;
	}
}

void BankEmployee::view(unsigned taskID) const
{
	tasks[taskID]->viewDetails();
}

void BankEmployee::removeTask(unsigned id)
{
	tasks.popAt(id);
}

Task* BankEmployee::approve(unsigned taskID)
{
	Task* nextTask = tasks[taskID - 1]->finish(); // can be nullptr if is not then i must handle it outside
	removeTask(taskID - 1);
	return nextTask;
}
unsigned BankEmployee::getTaskCount() const {
	return tasks.getSize();
}

void BankEmployee::disapprove(unsigned taskID, const MyString& message)
{
	MyString infiks = "Your ";
	infiks+=tasks[taskID - 1]->getType();
	infiks += " request was not approved. Reason: ";
	infiks += message;
	tasks[taskID - 1]->getClient().addMessage(infiks);
	removeTask(taskID - 1);

}

Task* BankEmployee::validate(unsigned taskID)
{
	PolymorphicPtr<Task> currentTask = tasks[taskID - 1];
	if (currentTask->getType() != "Change Not Validated") {
		throw std::exception("You cannot validate this response");
	}
	MyString oldBank = currentTask->getBankNameForChange();
	unsigned accountID = currentTask->getBankNameIdChange();
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
