#include "BankEmployee.h"

using std::cout;
using std::endl;



void BankEmployee::addTask(Task* task)
{
	tasks.pushBack(task)
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

void BankEmployee::help()
{
	std::cout << "Bank Employee commands:\n";
	std::cout << "1. tasks: Displays the tasks that need to be done. Each task has a type, name, and index.\n";
	std::cout << "2. view [task_id]: Shows all details about the task.\n";
	std::cout << "3. approve [task_id]: The employee completes the task and approves the request.\n";
	std::cout << "4. disapprove [task_id] [message]: The employee completes the task and denies the request.\n";
	std::cout << "5. validate [task_id]: The employee from the new bank makes a request to the old bank, validating whether the user has entered correct data. This validation does not go through an employee of the old bank and is returned immediately. Only Change tasks can be validated.\n";
}
