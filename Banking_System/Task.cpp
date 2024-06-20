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

const MyString& Task::getBankNameForChange() const
{
    throw std::exception("Not Implemented");
}

unsigned Task::getBankNameIdChange() const
{
    throw std::exception("Not Implemented");
}




