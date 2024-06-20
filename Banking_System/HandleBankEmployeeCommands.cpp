#include "HandleBankEmployeeCommands.h"
#include "ApproveCommand.h"
#include "DisapproveCommand.h"
#include "ShowTasksCommand.h"
#include "ValidateTaskCommand.h"
#include "ViewTaskCommand.h"
using std::cin;
using std::cout;
using std::endl;
void HandleBankEmployeeCommands::execute(BankSystem* app)
{
	
	ShowTasksCommand showTasksCommand;
	ApproveCommand approveCommand;
	DisapproveCommand disapproveCommand;
	ValidateTaskCommand validateTaskCommand;
	ViewTaskCommand viewTaskCommand;

	MyString command;
	cin >> command;
	
	if (command == "tasks")
	{
		showTasksCommand.execute(app);
	}
	else if (command == "view")
	{
		viewTaskCommand.execute(app);
	}
	else if (command == "approve")
	{
		approveCommand.execute(app);
	}
	else if (command == "disapprove")
	{
		disapproveCommand.execute(app);
	}
	else if (command == "validate")
	{
		validateTaskCommand.execute(app);
	}
	else if (command == "exit")
	{
		app->logout();
		std::cout << "Logged Out\n";
	}
	else if (command == "whoami")
	{
		app->getLoggedBankEmployee()->whoami();
	}
	else if (command == "help")
	{
		app->getLoggedBankEmployee()->help();
	}
	else {
		cout << "Unknown Command\n";
		cin.clear();
		cin.ignore(1024, '\n');
	}

}
