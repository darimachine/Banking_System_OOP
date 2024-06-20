#include "ApproveCommand.h"

void ApproveCommand::execute(BankSystem* app)
{
	unsigned taskID;
	std::cin >> taskID;
	BankEmployee* bankEmployee = app->getLoggedBankEmployee();
	try {
		Task* currentTask = bankEmployee->approve(taskID);
		if (currentTask)
		{
			MyString newBank =currentTask->getCurrentBankName();
			Bank& bankToTransfer = app->findBank(newBank);
			bankToTransfer.addTask(currentTask);
		}
	}
	catch (std::invalid_argument er)
	{
		std::cout << er.what() << std::endl;
	}
}
