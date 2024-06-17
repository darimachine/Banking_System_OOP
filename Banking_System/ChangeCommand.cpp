#include "ChangeCommand.h"

void ChangeCommand::execute(BankSystem* app)
{
	MyString newBankName;
	std::cin >> newBankName;

	MyString oldBankName;
	std::cin >> oldBankName;

	unsigned accountNumber;
	std::cin >> accountNumber;
	Client* client = app->getLoggedClient();
	try {
		Bank& newBank = app->findBank(newBankName);
		Task* task = client->change(newBankName, oldBankName, accountNumber);
		newBank.addTask(task);
	}
	catch (std::invalid_argument er)
	{
		std::cout << er.what() << std::endl;
	}
}
