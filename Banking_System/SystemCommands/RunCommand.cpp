#include "RunCommand.h"
#include "HandleBankEmployeeCommands.h"
#include "HandleClientCommands.h"
#include "HandleExternalEmployeeCommand.h"
#include "HandleNoneCommand.h"
using std::cout;
using std::endl;
void RunCommand::execute(BankSystem* app)
{
	cout << "  Instructions:\n";
	cout << " - create_bank <bank_name> (creates banks)\n";
	cout << " - signup (Open menu for signing up an client employee or external employee)\n";
	cout << " - login (Open menu for login with username and password)\n";
	cout << " - save (You can type save anytime to save current Proggres and exit the program)\n";
	cout << " - load (You can type load anytime to load the previous proggres with (If you are current logged it will change the logged user to the previous logged one!!!), loadst everything from previous session)\n";
	cout << " - help (When you are loged type help for more instruction what you can make!!)\n";
	while (true)
	{
		LoggedUserType type = app->getType();

		HandleNoneCommand noneCommand;
		HandleClientCommands clientCommand;
		HandleBankEmployeeCommands bankEmployeCommand;
		HandleExternalEmployeeCommand  externalEmployeCommand;

		switch (type)
		{
		case LoggedUserType::None: {
			noneCommand.execute(app);
			break;
		}

		case LoggedUserType::Client:
		{
			clientCommand.execute(app);
			break;
		}

		case LoggedUserType::BankEmployee:
		{
			bankEmployeCommand.execute(app);
			break;
		}
		case LoggedUserType::ExternalEmployee:
		{
			externalEmployeCommand.execute(app);
			break;
		}
		case LoggedUserType::Exited:
		{
			return;
		}
		default:
			break;
		}
	}
	

}
