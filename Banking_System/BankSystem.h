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

	User* loggedUser = nullptr;
	LoggedUserType loggedUserType = LoggedUserType::None;
	BankSystem() = default;
	BankSystem(const BankSystem&) = delete;
	BankSystem& operator =(const BankSystem&) = delete;
	bool userAlreadyExistsCheck(User*);
	bool bankAlreadyExistsCheck(const MyString& bankName);
public:

	static BankSystem& getInstance();

	Bank& findBank(const MyString& bankName);

	const Vector<Client>& getClients() const;
	const Vector<Bank>& getBanks() const;
	const Vector<BankEmployee>& getBankEmployee() const;
	void signUpBank(Bank&& bank);
	void signUpClient(Client&& client);
	void signUpBankEmployee(BankEmployee&& bankEmployee);
	void signUpExternalEmployee(ExternalCompanyEmployee&& externalEmployee);

	void login(const MyString& username, const MyString& password);
	
	void logout();

	const Vector<ExternalCompanyEmployee>& getExternalEmployees() const;
	const User* getLoggedUser() const;
	User* getLoggedUser();
	LoggedUserType getType() const;



};

