#include "ShowTasksCommand.h"

void ShowTasksCommand::execute(BankSystem* app)
{
	BankEmployee* bankEmployee = app->getLoggedBankEmployee(); // not reading
	bankEmployee->showTasks();
}
