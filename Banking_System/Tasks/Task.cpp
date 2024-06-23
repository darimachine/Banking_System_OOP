#include "Task.h"



Task::Task(const MyString& type, Client& clientInfo)
    :type(type),client(clientInfo)
{
}



const MyString& Task::getType() const
{
    return type;
   
}

Client& Task::getClient()
{
    return client;
    
}

const MyString& Task::getCurrentBankName() const
{
    throw std::exception("Not Implemented");
}

const MyString& Task::getNewBankName() const
{
    throw std::exception("Not Implemented");
}

unsigned Task::getAccountId() const
{
    throw std::exception("Not Implemented");
}




