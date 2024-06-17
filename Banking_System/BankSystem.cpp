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

void BankSystem::exit() const
{
    std::exit(0);
}
