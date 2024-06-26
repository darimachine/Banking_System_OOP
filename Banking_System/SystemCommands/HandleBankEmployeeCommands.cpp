#include "HandleBankEmployeeCommands.h"
#include "../BankEmployeeCommands/ApproveCommand.h"
#include "../BankEmployeeCommands/DisapproveCommand.h"
#include "../BankEmployeeCommands/ShowTasksCommand.h"
#include "../BankEmployeeCommands/ValidateTaskCommand.h"
#include "../BankEmployeeCommands/ViewTaskCommand.h"
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
	try {
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
		else if (command == "save")
		{
			app->save();
			app->exit();
		}
		else if (command == "load")
		{
			app->load();
		}
		else {
			cout << "Unknown Command\n";
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}
	catch (std::runtime_error& er)
	{
		cout << er.what() << endl;
	}
	catch (std::invalid_argument& er)
	{
		cout << er.what() << endl;
	}
	catch (std::exception& er)
	{
		cout << er.what() << endl;
	}
	catch (...)
	{
		cout << "Unknown Error\n";
	}
	

}
