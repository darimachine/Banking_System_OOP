#include "HandleClientCommands.h"
#include "../ClientCommands/ChangeCommand.h"
#include "../ClientCommands/CheckAvlCommand.h"
#include "../ClientCommands/CloseCommand.h"
#include "../ClientCommands/ListCommand.h"
#include "../ClientCommands/MessagesCommand.h"
#include "../ClientCommands/OpenCommand.h"
#include "../ClientCommands/RedeemCommand.h"

using std::cin;
using std::cout;
using std::endl;
void HandleClientCommands::execute(BankSystem* app)
{
	ChangeCommand changeCommand;
	CheckAvlCommand checkAvlCommand;
	CloseCommand closeCommand;
	ListCommand listCommand;
	MessagesCommand messagesCommand;
	RedeemCommand redeemCommand;
	OpenCommand openCommand;


	MyString command;
	cin >> command;

	if (command == "whoami")
	{
		app->getLoggedClient()->whoami();
	}
	else if (command == "open")
	{
		openCommand.execute(app);
	}
	else if (command == "close")
	{
		closeCommand.execute(app);
	}
	else if (command == "check_avl")
	{
		checkAvlCommand.execute(app);
	}
	else if (command == "redeem")
	{
		redeemCommand.execute(app);
	}
	else if (command == "change")
	{
		changeCommand.execute(app);
	}
	else if (command == "list")
	{
		listCommand.execute(app);
	}
	else if (command == "messages")
	{
		messagesCommand.execute(app);
	}
	else if (command == "help")
	{
		app->getLoggedClient()->help();
	}
	else if (command == "exit")
	{
		app->logout();
		std::cout << "Logged Out\n";
	}
	else {
		cout << "Unknown Command\n";
		cin.clear();
		cin.ignore(1024, '\n');
	}

}
