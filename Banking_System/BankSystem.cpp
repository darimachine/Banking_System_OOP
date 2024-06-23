#include "BankSystem.h"
using std::cout;
using std::endl;
bool BankSystem::userAlreadyExistsCheck(User* user)
{

    unsigned clientSize = clients.getSize();
    for (int i = 0; i < clientSize; i++)
    {
        if (clients[i].getName() == user->getName() || clients[i].getEGN() == user->getEGN()) {
            throw std::invalid_argument("User Already Exists(Name or EGN are the Same)");
        }
    }
    unsigned totalBanks = banks.getSize();
    for (int i = 0; i < totalBanks; i++)
    {
        Vector<BankEmployee> employees = banks[i].getBankEmployees();
        unsigned employeeSize = employees.getSize();
        for (int i = 0; i < employeeSize; i++)
        {
            if (employees[i].getName() == user->getName() || employees[i].getEGN() == user->getEGN()) {
                throw std::invalid_argument("User Already Exists(Name or EGN are the Same)");
            }
        }
    }
    
  
    unsigned externalEmployeeSize = externalEmployees.getSize();
    for (int i = 0; i < externalEmployeeSize; i++)
    {
        if (externalEmployees[i].getName() == user->getName() || externalEmployees[i].getEGN() == user->getEGN()) {
            throw std::invalid_argument("User Already Exists(Name or EGN are the Same)");
        }
    }
    return false;

}

bool BankSystem::bankAlreadyExistsCheck(const MyString& bankName)
{
    unsigned size = banks.getSize();
    for (int i = 0; i < size; i++)
    {
        if (banks[i].getName() == bankName) {
            return true;
        }
    }
    return false;
}

Client& BankSystem::findClientByName(const MyString& name)
{
    unsigned size = clients.getSize();
    for (int i = 0; i < size; i++)
    {
        if (clients[i].getName() == name)
        {
            return clients[i];
        }
    }
    throw std::invalid_argument("Client not Found");
}

ExternalCompanyEmployee& BankSystem::findExternalCompanyEmployeeByName(const MyString& name)
{

    unsigned size = externalEmployees.getSize();
    for (int i = 0; i < size; i++)
    {
        if (externalEmployees[i].getName() == name)
        {
            return externalEmployees[i];
        }
    }
    throw std::invalid_argument("External Employee not Found");
}

BankEmployee& BankSystem::findBankEmployeeByName(const MyString& name)
{
    unsigned totalBanks = banks.getSize();
    for (int i = 0; i < totalBanks; i++)
    {
        Vector<BankEmployee>& employees = banks[i].getBankEmployees();
        unsigned employeeSize = employees.getSize();
        for (int i = 0; i < employeeSize; i++)
        {
            if (employees[i].getName() == name) {
                return employees[i];
            }
        }
    }
    throw std::invalid_argument("Bank Employe Dont Exist");
}

int BankSystem::getTotalTasks() const
{  
    int totalTaskCount = 0;
    int size = banks.getSize();
    for (int i = 0; i < size; i++)
    {
        Vector<BankEmployee> employees = banks[i].getBankEmployees();
        int size = employees.getSize();
        for (int i = 0; i < size; i++)
        {
            totalTaskCount+=employees[i].getTaskCount();
        }
    }
    return totalTaskCount;
}

void BankSystem::saveClients() const
{
    std::ofstream ofs("clients.dat", std::ios::binary);
    if (!ofs.is_open())
    {
        return;
    }
    int size = clients.getSize();
    ofs.write((const char*)&size, sizeof(size));
    for (int i = 0; i < size; i++)
    {
        clients[i].saveToFile(ofs);
    }
    ofs.close();
}
void BankSystem::readClients()
{
    std::ifstream ifs("clients.dat", std::ios::binary);
    if (!ifs.is_open())
    {
        return;
    }
    int size;
    ifs.read((char*)&size, sizeof(size));
    if (size == 0) return;
    for (int i = 0; i < size; i++)
    {
        Client cl;
        cl.readFromFile(ifs);
        clients.pushBack(std::move(cl));
    }
    ifs.close();
}

void BankSystem::saveBanks() const
{
    std::ofstream ofs("banks.dat", std::ios::binary);
    if (!ofs.is_open())
    {
        return;
    }
    int size = banks.getSize();
    ofs.write((const char*)&size, sizeof(size));
    for (int i = 0; i < size; i++)
    {
        banks[i].saveToFile(ofs);
    }
    ofs.close();
}

void BankSystem::readBanks()
{
    std::ifstream ifs("banks.dat", std::ios::binary);
    if (!ifs.is_open())
    {
        return;
    }
    int size;
    ifs.read((char*)&size, sizeof(size));
    if (size == 0) return;
    for (int i = 0; i < size; i++)
    {
        Bank bank;
        bank.readFromFile(ifs);
        banks.pushBack(std::move(bank));
    }
    ifs.close();
}

void BankSystem::saveExternalEmployees() const
{
    std::ofstream ofs("externalEmployees.dat", std::ios::binary);
    if (!ofs.is_open())
    {
        return;
    }
    int size = externalEmployees.getSize();
    ofs.write((const char*)&size, sizeof(size));
    for (int i = 0; i < size; i++)
    {
        externalEmployees[i].saveToFile(ofs);
    }
    ofs.close();
}

void BankSystem::readExternalEmployee()
{
    std::ifstream ifs("externalEmployees.dat", std::ios::binary);
    if (!ifs.is_open())
    {
        return;
    }
    int size;
    ifs.read((char*)&size, sizeof(size));
    if (size == 0) return;
    for (int i = 0; i < size; i++)
    {
        ExternalCompanyEmployee externalEmployee;
        externalEmployee.readFromFile(ifs);
        externalEmployees.pushBack(std::move(externalEmployee));
    }
    ifs.close();
}

void BankSystem::saveLoggedUser() const
{
    std::ofstream ofs("loggedUser.dat", std::ios::binary);
    if (!ofs.is_open())
    {
        return;
    }
    ofs.write((const char*)&loggedUserType, sizeof(loggedUserType));
    if (loggedUserType == LoggedUserType::None)
    {
        return;
    }
    else if (loggedUserType == LoggedUserType::Client)
    {
        MyString loggedClientName = clientLogged->getName();
        loggedClientName.saveToFile(ofs);
    }
    else if (loggedUserType == LoggedUserType::BankEmployee)
    {
        MyString loggedBankEmployeeName = bankEmployeeLogged->getName();
        loggedBankEmployeeName.saveToFile(ofs);
    }
    else if (loggedUserType == LoggedUserType::ExternalEmployee)
    {
        MyString loggedExternalEmployeeName = externalEmployeeLogged->getName();
        loggedExternalEmployeeName.saveToFile(ofs);
    }
    ofs.close();
}

void BankSystem::readLoggedUser()
{
    std::ifstream ifs("loggedUser.dat", std::ios::binary);
    if (!ifs.is_open())
    {
        return;
    }
    ifs.read((char*)&loggedUserType, sizeof(loggedUserType));
    if (loggedUserType == LoggedUserType::None)
    {
        return;
    }
    else if (loggedUserType == LoggedUserType::Client)
    {
        MyString loggedClientName;
        loggedClientName.readFromFile(ifs);
        clientLogged=&findClientByName(loggedClientName);
       
    }
    else if (loggedUserType == LoggedUserType::BankEmployee)
    {
        MyString loggedBankEmployeeName;
        loggedBankEmployeeName.readFromFile(ifs);
        bankEmployeeLogged = &findBankEmployeeByName(loggedBankEmployeeName);
    }
    else if (loggedUserType == LoggedUserType::ExternalEmployee)
    {
        MyString loggedExternalEmployeeName;
        loggedExternalEmployeeName.readFromFile(ifs);
        externalEmployeeLogged = &findExternalCompanyEmployeeByName(loggedExternalEmployeeName);
        
    }
    ifs.close();
}

void BankSystem::saveTasks() const
{
    std::ofstream ofs("tasks.dat", std::ios::binary);
    if (!ofs.is_open())
    {
        return;
    }
    int totalTasks = getTotalTasks();
    ofs.write((const char*)&totalTasks, sizeof(totalTasks));
    if (totalTasks == 0) return;
    int size = banks.getSize();
    for (int i = 0; i < size; i++)
    {
        Vector<BankEmployee> employees = banks[i].getBankEmployees();
        int size = employees.getSize();
        for (int i = 0; i < size; i++)
        {
            employees[i].saveTasksToFile(ofs);
        }
    }
    ofs.close();
}

void BankSystem::readTasks()
{
    std::ifstream ifs("tasks.dat", std::ios::binary);
    if (!ifs.is_open())
    {
        return;
    }
    int totalTasks;
    ifs.read((char*)&totalTasks, sizeof(totalTasks));
    if (totalTasks == 0) return;
    for (int i = 0; i < totalTasks; i++)
    {
        MyString type;
        type.readFromFile(ifs);
        if (type == "Open")
        {
            MyString bankName,clientName;
            bankName.readFromFile(ifs);
            clientName.readFromFile(ifs);
            Bank& bank = findBank(bankName);
            Client& client = findClientByName(clientName);
            Task* task= new OpenAccountTask(bankName, client);
            bank.addTask(task);

        }
        else if (type == "Close")
        {
            MyString bankName, clientName;
            bankName.readFromFile(ifs);
            clientName.readFromFile(ifs);

            unsigned accountId;
            ifs.read((char*)&accountId, sizeof(accountId));

            Bank& bank = findBank(bankName);
            Client& client = findClientByName(clientName);

            Task* task = new CloseAccountTask(client, bankName, accountId);
            bank.addTask(task);
        }
        else if (type == "Change Not Validated")
        {
            MyString bankName, clientName,newBankName;
            bankName.readFromFile(ifs);
            clientName.readFromFile(ifs);

            unsigned accountId;
            ifs.read((char*)&accountId, sizeof(accountId));

            newBankName.readFromFile(ifs);
            Bank& bank = findBank(newBankName);
            Client& client = findClientByName(clientName);
            Task* task = new ChangeAccountTaskNoValidated(newBankName, client, bankName, accountId);
            bank.addTask(task);

        }
        else if (type == "Change Validated")
        {
            MyString bankName, clientName, newBankName;
            bankName.readFromFile(ifs);
            clientName.readFromFile(ifs);

            unsigned accountId;
            ifs.read((char*)&accountId, sizeof(accountId));

            newBankName.readFromFile(ifs);
            Bank& bank = findBank(bankName);
            Client& client = findClientByName(clientName);
            Task* task = new ChangeAccountTaskValidated(newBankName, client, bankName, accountId);
            bank.addTask(task);
        }
        else if (type == "Change Approved")
        {
            MyString bankName, clientName, newBankName;
            bankName.readFromFile(ifs);
            clientName.readFromFile(ifs);

            unsigned accountId;
            ifs.read((char*)&accountId, sizeof(accountId));

            newBankName.readFromFile(ifs);
            Bank& bank = findBank(newBankName);
            Client& client = findClientByName(clientName);
            Task* task = new ChangeAccountTaskApproved(newBankName, client, bankName, accountId);
            bank.addTask(task);
        }

    }
    ifs.close();
   
}


BankSystem& BankSystem::getInstance()
{
    static BankSystem obj;
    return obj;

}

Bank& BankSystem::findBank(const MyString& bankName)
{
    unsigned size = banks.getSize();
    for (int i = 0; i < size; i++)
    {
        if (banks[i].getName() == bankName) 
        {
            return banks[i];
        }
    }
    throw std::invalid_argument("There is no such bank");
    
}

Client& BankSystem::getClientByEgn(const MyString& egn) 
{
    unsigned size = clients.getSize();
    for (int i = 0; i < size; i++)
    {
        if (clients[i].getEGN() == egn)
        {
            return clients[i];
        }
    }
    throw std::invalid_argument("Client with this EGN does not exist");
}

const Vector<Client>& BankSystem::getClients() const
{
    return clients;
}

const Vector<Bank>& BankSystem::getBanks() const
{
    return banks;
}


void BankSystem::signUpBank(Bank& bank)
{
    
    if (bankAlreadyExistsCheck(bank.getName())) {
        throw std::invalid_argument("Bank Already Exists");
    }
    banks.pushBack(bank);
    
    
}

void BankSystem::signUpClient(Client&& client)
{
    userAlreadyExistsCheck(&client);
    
    clients.pushBack(std::move(client));
}

void BankSystem::signUpBankEmployee(BankEmployee& bankEmployee)
{
    userAlreadyExistsCheck(&bankEmployee);
    if (!bankAlreadyExistsCheck(bankEmployee.getBankAssociated())) {
        throw std::invalid_argument("Bank Does Not Exists");
    }
   
    Bank& bank = findBank(bankEmployee.getBankAssociated());
    bank.addEmployee(bankEmployee);
}

void BankSystem::signUpExternalEmployee(ExternalCompanyEmployee&& externalEmployee)
{
    userAlreadyExistsCheck(&externalEmployee);
    externalEmployees.pushBack(externalEmployee);
}

void BankSystem::login(const MyString& username, const MyString& password)
{
    unsigned bankSize = banks.getSize();
    for (int i = 0; i < bankSize; i++)
    {
        Vector<BankEmployee>& employeess = banks[i].getBankEmployees();
        unsigned size = employeess.getSize();
        for (int i = 0; i < size; i++)
        {
            if (employeess[i].getName() == username)
            {
                if (employeess[i].isValidPassword(password))
                {
                    bankEmployeeLogged = &employeess[i];
                    loggedUserType = LoggedUserType::BankEmployee;
                    return;
                }
                throw std::runtime_error("Wrong Password");
            }
        }
    }
    unsigned clientCount = clients.getSize();
    unsigned externalEmployeeCount = externalEmployees.getSize();
    if (clientCount == 0 && externalEmployeeCount == 0)
    {
        throw std::runtime_error("No users in the system!");
    }
    for (int i = 0; i < clientCount; i++)
    {
        if (clients[i].getName() == username)
        {
            if (clients[i].isValidPassword(password))
            {
                clientLogged = &clients[i];
             
                loggedUserType = LoggedUserType::Client;
                return;
            }
            throw std::runtime_error("Wrong Password");
        }
    }
    for (int i = 0; i < externalEmployeeCount; i++)
    {
        if (externalEmployees[i].getName() == username)
        {
            if (externalEmployees[i].isValidPassword(password))
            {
                externalEmployeeLogged = &externalEmployees[i];
                loggedUserType = LoggedUserType::ExternalEmployee;
                return;
            }
            throw std::runtime_error("Wrong Password");
        }
    }
    throw std::runtime_error("Wrong Username");
}

void BankSystem::logout()
{
    switch (loggedUserType)
    {   
        case LoggedUserType::None:
        {
            cout << "Already logOuted\n";
            break;
        }
        
        case LoggedUserType::Client:
        {
            clientLogged = nullptr;
            loggedUserType = LoggedUserType::None;
            break;
        }
        
        case LoggedUserType::BankEmployee: {
            bankEmployeeLogged = nullptr;
            loggedUserType = LoggedUserType::None;
            break;
        }
       
        case LoggedUserType::ExternalEmployee:
        {
            externalEmployeeLogged = nullptr;
            loggedUserType = LoggedUserType::None;
            break;
        }
        default:
            break;
    }
}

const Vector<ExternalCompanyEmployee>& BankSystem::getExternalEmployees() const
{
    return externalEmployees;
}

const Client* BankSystem::getLoggedClient() const
{
    return clientLogged;
}

Client* BankSystem::getLoggedClient()
{
    return clientLogged;
}

const BankEmployee* BankSystem::getLoggedBankEmployee() const
{
    return bankEmployeeLogged;
}

BankEmployee* BankSystem::getLoggedBankEmployee()
{
    
    return bankEmployeeLogged;
}

const ExternalCompanyEmployee* BankSystem::getLoggedExternalEmployee() const
{
    return externalEmployeeLogged;
}

ExternalCompanyEmployee* BankSystem::getLoggedExternalEmployee()
{
    return externalEmployeeLogged;
}


LoggedUserType BankSystem::getType() const
{
    return loggedUserType;
}

void BankSystem::save() const
{
    saveBanks();
    saveClients();
    saveExternalEmployees();
    saveLoggedUser();
    saveTasks();
}

void BankSystem::load()
{
    readBanks();
    readClients();
    readExternalEmployee();
    readLoggedUser();
    readTasks();
}

void BankSystem::exit()
{
    loggedUserType = LoggedUserType::Exited;
}
