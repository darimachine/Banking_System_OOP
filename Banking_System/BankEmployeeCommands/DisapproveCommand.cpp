#include "DisapproveCommand.h"

void DisapproveCommand::execute(BankSystem* app)
{
	unsigned taskID;
	std::cin >> taskID;

	MyString message;
	char message2[1024];
	std::cin.getline(message2, 1024);
	message = message2;
	BankEmployee* bankEmployee = app->getLoggedBankEmployee();
	try {
		bankEmployee->disapprove(taskID,message);
	}
	catch (std::invalid_argument& er)
	{
		std::cout << er.what() << std::endl;
	}
}
