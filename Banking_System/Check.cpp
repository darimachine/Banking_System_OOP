#include "Check.h"
#include <ctime>
#pragma warning(disable : 4996)
using std::cout;
void Check::generateUniqueCheck()
{
    makeUniqueTime();
    // Allowed Symbols
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (int i = 0; i < 3; ++i) {
        uniqueCode += charset[rand() % (sizeof(charset) - 1)];
    }
   
}
//Guarantees unique code..
void Check::makeUniqueTime()
{
    
    std::time_t now = std::time(0); // gets current time
    char timestamp[20];
    
    //formats time and saves it to timestamp array as an string
    std::strftime(timestamp, sizeof(timestamp), "%Y%m%d%H%M%S", std::localtime(&now));
}

Check::Check(unsigned cashToSend) :cashToSend(cashToSend)
{
    generateUniqueCheck();
}

unsigned Check::getCash() const
{
    return cashToSend;
}
