#include "RedeemCommand.h"

void RedeemCommand::execute(BankSystem* app)
{
	MyString bankName;
	std::cin >> bankName;

	unsigned accountNumber;
	std::cin >> accountNumber;

	MyString verificationCode;
	std::cin >> verificationCode;
	Client* client = app->getLoggedClient();
	try {
		client->redeem(bankName, accountNumber, verificationCode);
	}
	catch (std::invalid_argument er)
	{
		std::cout << er.what() << std::endl;
	}
}
