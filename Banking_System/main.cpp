// Banking_System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "BankSystem.h"
#include "SystemCommands/RunCommand.h"


using std::cout;
using std::endl;
int main()
{
  /*  _CrtDumpMemoryLeaks();
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);*/
    std::srand((std::time(0)));
    BankSystem* app = &BankSystem::getInstance();
    RunCommand run;
    run.execute(app);
    
}


