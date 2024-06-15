#include "BankSystem.h"

BankSystem& BankSystem::getInstance()
{
    static BankSystem obj;
    return obj;

}
