#include "ViewTaskCommand.h"

void ViewTaskCommand::execute(BankSystem* app)
{
	unsigned taskID;
	std::cin >> taskID;
	BankEmployee* bankEmployee = app->getLoggedBankEmployee();
	try {
		bankEmployee->view(taskID);
	}
	catch (std::invalid_argument& er)
	{
		std::cout << er.what() << std::endl;
	}
	
}
