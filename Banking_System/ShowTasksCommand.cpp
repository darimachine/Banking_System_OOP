#include "ShowTasksCommand.h"

void ShowTasksCommand::execute(BankSystem* app)
{
	BankEmployee* bankEmployee = app->getLoggedBankEmployee();
	bankEmployee->showTasks();
}
