#include "BankSystem.h"

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
            throw std::runtime_error("Bank Already Exists");
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
    
    bankAlreadyExistsCheck(bank.getName());
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
                loggedUser = &clients[i];
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
                loggedUser = &bankEmployees[i];
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
                loggedUser = &externalEmployees[i];
                loggedUserType = LoggedUserType::ExternalEmployee;
                return;
            }
            throw std::runtime_error("Wrong Password");
        }
    }
}

void BankSystem::logout()
{
    loggedUser = nullptr;
    loggedUserType = LoggedUserType::None;
}

const Vector<ExternalCompanyEmployee>& BankSystem::getExternalEmployees() const
{
    return externalEmployees;
}

const User* BankSystem::getLoggedUser() const
{
    return loggedUser;
}

User* BankSystem::getLoggedUser()
{
    return loggedUser;
}

LoggedUserType BankSystem::getType() const
{
    return loggedUserType;
}
