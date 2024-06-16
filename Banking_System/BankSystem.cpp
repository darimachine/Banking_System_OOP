#include "BankSystem.h"
using std::cout;
using std::endl;
bool BankSystem::userAlreadyExistsCheck(User* user)
{

    unsigned clientSize = clients.getSize();
    for (int i = 0; i < clientSize; i++)
    {
        if (clients[i].getName() == user->getName()) {
            throw std::runtime_error("User Already Exists");
        }
    }
    unsigned bankEmployeeSize = bankEmployees.getSize();
    for (int i = 0; i < bankEmployeeSize; i++)
    {
        if (bankEmployees[i].getName() == user->getName()) {
            throw std::runtime_error("User Already Exists");
        }
    }
    unsigned externalEmployeeSize = externalEmployees.getSize();
    for (int i = 0; i < externalEmployeeSize; i++)
    {
        if (externalEmployees[i].getName() == user->getName()) {
            throw std::runtime_error("User Already Exists");
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
        if (banks[i].getName() == bankName) {
            return banks[i];
        }
    }
    throw std::runtime_error("There is no such bank");
    
}

const Vector<Client>& BankSystem::getClients() const
{
    return clients;
}

const Vector<Bank>& BankSystem::getBanks() const
{
    return banks;
}

const Vector<BankEmployee>& BankSystem::getBankEmployee() const
{
    return bankEmployees;
}

void BankSystem::signUpBank(Bank&& bank)
{
    
    if (bankAlreadyExistsCheck(bank.getName())) {
        throw std::invalid_argument("Bank Already Exists");
    }
    banks.pushBack(std::move(bank));
    
    
}

void BankSystem::signUpClient(Client&& client)
{
    userAlreadyExistsCheck(&client);
    
    clients.pushBack(std::move(client));
}

void BankSystem::signUpBankEmployee(BankEmployee&& bankEmployee)
{
    userAlreadyExistsCheck(&bankEmployee);
    if (!bankAlreadyExistsCheck(bankEmployee.getBankAssociated())) {
        throw std::invalid_argument("Bank Does Not Exists");
    }
    bankEmployees.pushBack(std::move(bankEmployee));
}

void BankSystem::signUpExternalEmployee(ExternalCompanyEmployee&& externalEmployee)
{
    userAlreadyExistsCheck(&externalEmployee);
    externalEmployees.pushBack(externalEmployee);
}

void BankSystem::login(const MyString& username, const MyString& password)
{
    unsigned clientCount = clients.getSize();
    unsigned bankEmployeeCount = bankEmployees.getSize();
    unsigned externalEmployeeCount = externalEmployees.getSize();
    if (clientCount == 0 && bankEmployeeCount == 0 && externalEmployeeCount == 0)
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
    for (int i = 0; i < bankEmployeeCount; i++)
    {
        if (bankEmployees[i].getName() == username)
        {
            if (bankEmployees[i].isValidPassword(password))
            {
                bankEmployeeLogged = &bankEmployees[i];
                loggedUserType = LoggedUserType::BankEmployee;

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
