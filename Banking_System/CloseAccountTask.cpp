#include "CloseAccountTask.h"
#include "Client.h"

using std::cout;
using std::endl;
CloseAccountTask::CloseAccountTask(Client& client, Bill& account)
    :Task("Close",client),bankAccount(account)
{
}
void CloseAccountTask::viewDetails() const
{
    cout << type << "request from:\n";
    cout << "Name: " << client.getName() << endl;
    cout << "EGN: " << client.getEGN() << endl;
    cout << "Age: " << client.getAge() << endl;
    cout << "Bank: " << bankAccount.getBankName() << endl;
    cout << "Account number: " << bankAccount.getID() << endl;
    cout << "Balance: " << bankAccount.getBalance() << "$\n";
}

void CloseAccountTask::viewMessage() const
{
    cout << type << " - " << client.getName() << " wants to close accoutn with id " << bankAccount.getID() << ".\n";
    //[2] Close - Stancho wants to close account with id 2903.
}

Task* CloseAccountTask::clone() const
{
    return new CloseAccountTask(*this);
}
