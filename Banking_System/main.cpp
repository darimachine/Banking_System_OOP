// Banking_System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Check.h"
#include "User.h"
#include "Client.h"
#include "PolyMorphic_Ptr.hpp"
#include "Bill.h"
#include "BankEmployee.h"
#include "Bank.h"
#include <crtdbg.h>
using std::cout;
using std::endl;
int main()
{
    std::srand((std::time(0)));
    //_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
   /* while (1){*/
    
        //_CrtDumpMemoryLeaks();
        Client client("Serhan", "1234567890", 12, "123");
        Bill b("RandomBank", 150, 1);
        client.addBill(b);
        //int* shiban = new int(5);
        //Task* me = new OpenAccountTask("a",client);
        Task* task = client.open("NewBank");
        BankEmployee b1("Sean", "1234560890", 12, "123","RandomBank");
        BankEmployee b2("Bean", "9234560890", 12, "123", "RandomBank");
        b1.addTask(task);
        task->viewDetails();
        task->viewMessage();
        b1.approve(1);
        
        client.messages();
        int id;
        std::cin >> id;
        client.getBill(1).deposit(120);
        client.check_avl("NewBank", id);
  
        
        
        
        //delete task;
    //}
   
  
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
