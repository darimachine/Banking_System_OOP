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
