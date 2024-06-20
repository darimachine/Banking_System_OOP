#include "HandleNoneCommand.h"
#include "CreateBankCommand.h"
#include "LoginCommand.h"
#include "RegisterCommand.h"
using std::cout;
using std::cin;
using std::endl;
void HandleNoneCommand::execute(BankSystem* app)
{
	CreateBankCommand createBankCommand;
	LoginCommand loginCommand;
	RegisterCommand registerCommand;
	MyString command;
	cin >> command;
	if (command == "create_bank")
	{
		createBankCommand.execute(app);
	}
	else if (command == "signup")
	{
		registerCommand.execute(app);
	}
	else if (command == "login")
	{
		loginCommand.execute(app);
	}
	else if (command == "exit")
	{
		app->exit();
	}
	else {
		cout << "Unknown Command\n";
		cin.clear();
		cin.ignore(1024, '\n');
	}
	
	// if typed exit system.exit(0);
}
