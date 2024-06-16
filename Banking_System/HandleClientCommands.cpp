#include "HandleClientCommands.h"
#include "ChangeCommand.h"
#include "CheckAvlCommand.h"
#include "CloseCommand.h"
#include "ListCommand.h"
#include "MessagesCommand.h"
#include "OpenCommand.h"
#include "RedeemCommand.h"
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

}
