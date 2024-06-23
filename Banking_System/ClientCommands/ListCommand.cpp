#include "ListCommand.h"

void ListCommand::execute(BankSystem* app)
{
	MyString bankName;
	std::cin >> bankName;

	Client* client = app->getLoggedClient();
	try {
		Bank& isValid = app->findBank(bankName);
		client->list(bankName);
	}
	catch (std::invalid_argument& er)
	{
		std::cout << er.what() << std::endl;
	}
}
