#include "LoginCommand.h"

void LoginCommand::execute(BankSystem* app)
{
	MyString name;
	MyString password;
	std::cout << "Name: ";
	std::cin >> name;

	std::cout << "Password: ";
	std::cin >> password;
	try {
		app->login(name, password);
		std::cout << "Login Sucesfull: "<<name << std::endl;
	}
	catch (std::runtime_error& er)
	{
		std::cout << er.what() << std::endl;
	}
	catch (std::invalid_argument& er)
	{
		std::cout << er.what() << std::endl;
	}
	
}
