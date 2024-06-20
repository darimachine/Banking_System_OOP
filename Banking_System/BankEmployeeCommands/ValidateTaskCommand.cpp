#include "ValidateTaskCommand.h"

void ValidateTaskCommand::execute(BankSystem* app)
{
	unsigned taskID;
	std::cin >> taskID;
	BankEmployee* bankEmployee = app->getLoggedBankEmployee();
	try {
		Task* current= bankEmployee->validate(taskID);
		MyString oldBank = current->getCurrentBankName();
		Bank& bank = app->findBank(oldBank);
		bank.addTask(current);
	}
	catch (std::invalid_argument er)
	{
		std::cout << er.what() << std::endl;
	}
}
