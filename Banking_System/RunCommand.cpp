#include "RunCommand.h"
#include "HandleBankEmployeeCommands.h"
#include "HandleClientCommands.h"
#include "HandleExternalEmployeeCommand.h"
#include "HandleNoneCommand.h"
void RunCommand::execute(BankSystem* app)
{
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
			break;
		case LoggedUserType::ExternalEmployee:
			break;
		default:
			break;
		}
	}
	

}
