#include "CheckAvlCommand.h"

void CheckAvlCommand::execute(BankSystem* app)
{
	MyString bankName;
	std::cin >> bankName;

	unsigned accountNumber;
	std::cin >> accountNumber;

	Client* client = app->getLoggedClient();
	try {
		client->check_avl(bankName, accountNumber);
	}
	catch (std::invalid_argument er)
	{
		std::cout << er.what() << std::endl;
	}
		
	
}
