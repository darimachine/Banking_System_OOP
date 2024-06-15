#include "CloseAccountTask.h"
#include "Client.h"

using std::cout;
using std::endl;
CloseAccountTask::CloseAccountTask(Client& client, const MyString& bank, unsigned id)
    :Task("Close",client),bank(bank),accountID(id)
{
}
void CloseAccountTask::viewDetails() const
{
    int index = client.findbankAccountIndex(bank, accountID);
    cout << type << "request from:\n";
    cout << "Name: " << client.getName() << endl;
    cout << "EGN: " << client.getEGN() << endl;
    cout << "Age: " << client.getAge() << endl;
    cout << "Bank: " << bank << endl;
    cout << "Account number: " << accountID << endl;
    cout << "Balance: " << client.getBill(index).getBalance() << "$\n";
}

void CloseAccountTask::viewMessage() const
{
    cout << type << " - " << client.getName() << " wants to close accoutn with id " << accountID << ".\n";
    //[2] Close - Stancho wants to close account with id 2903.
}

Task* CloseAccountTask::clone() const
{
    return new CloseAccountTask(*this);
}

Task* CloseAccountTask::finish()
{
    return nullptr;
}
