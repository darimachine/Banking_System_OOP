#pragma once
#include "Client.h"
#include "Bank.h"
#include "BankEmployee.h"
#include "ExternalCompanyEmployee.h"
enum class LoggedUserType {
	None,
	Client,
	BankEmployee,
	ExternalEmployee
};
class BankSystem
{
	Vector<Bank> banks;
	Vector<Client> clients;
	Vector<BankEmployee> bankEmployees;
	Vector<ExternalCompanyEmployee> externalEmployees;
	User* currentLoggedUser;
	LoggedUserType logged = LoggedUserType::None;
	BankSystem() = default;
	BankSystem(const BankSystem&) = delete;
	BankSystem& operator = (const BankSystem&) = delete;
public:

	static BankSystem& getInstance();
	
	const Vector<Client>& getClients() const;
	const Vector<Bank>& getBanks() const;
	const Vector<BankEmployee>& getBankEmployee() const;

	const Vector<Bank>& getBanks() const;
};

