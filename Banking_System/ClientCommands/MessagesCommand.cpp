#include "MessagesCommand.h"

void MessagesCommand::execute(BankSystem* app)
{
	Client* client = app->getLoggedClient();
	client->messages();
}
