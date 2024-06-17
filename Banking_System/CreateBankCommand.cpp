#include "CreateBankCommand.h"

void CreateBankCommand::execute(BankSystem* app)
{
	MyString bankName;
	std::cin >> bankName;
	Bank bank(std::move(bankName));
	try {
		app->signUpBank(bank);
		std::cout << "Bank Created Succesfully\n";
	}
	catch(std::runtime_error er)
	{
		std::cout << er.what() << std::endl;
	}
	
}
