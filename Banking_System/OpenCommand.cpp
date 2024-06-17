#include "OpenCommand.h"
#include "OpenAccountTask.h"
void OpenCommand::execute(BankSystem* app)
{
	MyString bankName;
	std::cin >> bankName;
	Client* client = app->getLoggedClient();
	try {
		Bank& b = app->findBank(bankName);
		Task* task =client->open(bankName);
		b.addTask(task);

	}
	catch (std::invalid_argument er)
	{
		std::cout << er.what() << std::endl;
	}
	catch (std::exception er)
	{
		std::cout << er.what() << std::endl;
	}
	
}
