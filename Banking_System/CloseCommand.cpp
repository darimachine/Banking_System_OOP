#include "CloseCommand.h"

void CloseCommand::execute(BankSystem* app)
{
	MyString bankName;
	std::cin >> bankName;

	unsigned accountNumber;
	std::cin >> accountNumber;
	Client* client = app->getLoggedClient();
	try {
		Bank& b = app->findBank(bankName);
		Task* task = client->close(bankName, accountNumber);
		b.addTask(task);
	}
	catch (std::invalid_argument er)
	{
		std::cout << er.what() << std::endl;
	}
	
	
}
