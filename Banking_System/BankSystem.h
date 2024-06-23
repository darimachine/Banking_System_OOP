#pragma once
#include "Client.h"
#include "Bank.h"
#include "Users/BankEmployee.h"
#include "ExternalCompanyEmployee.h"
enum class LoggedUserType {
	None,
	Client,
	BankEmployee,
	ExternalEmployee,
	Exited
};
class BankSystem
{
	Vector<Bank> banks;
	Vector<Client> clients;
	
	Vector<ExternalCompanyEmployee> externalEmployees;
	// WITHOUT DYNAMIC_CAST!!!!!!!!
	Client* clientLogged = nullptr;
	BankEmployee* bankEmployeeLogged = nullptr;
	ExternalCompanyEmployee* externalEmployeeLogged = nullptr;

	LoggedUserType loggedUserType = LoggedUserType::None;
	
	BankSystem() = default;
	BankSystem(const BankSystem&) = delete;
	BankSystem& operator=(const BankSystem&) = delete;

	bool userAlreadyExistsCheck(User*);
	bool bankAlreadyExistsCheck(const MyString& bankName);

	Client& findClientByName(const MyString& name);
	ExternalCompanyEmployee& findExternalCompanyEmployeeByName(const MyString& name);
	BankEmployee& findBankEmployeeByName(const MyString& name);
	//Task Saving
	int getTotalTasks() const;
	//files SAVE,READ
	void saveClients() const;
	void readClients();

	void saveBanks() const;
	void readBanks();

	void saveExternalEmployees() const;
	void readExternalEmployee();

	void saveLoggedUser() const;
	void readLoggedUser();
	
	void saveTasks() const;
	void readTasks();

	
	
public:

	static BankSystem& getInstance();

	Bank& findBank(const MyString& bankName);

	Client& getClientByEgn(const MyString& egn);

	const Vector<Client>& getClients() const;
	const Vector<Bank>& getBanks() const;
	

	

	void signUpBank(Bank& bank);
	void signUpClient(Client&& client);
	void signUpBankEmployee(BankEmployee& bankEmployee);
	void signUpExternalEmployee(ExternalCompanyEmployee&& externalEmployee);

	void login(const MyString& username, const MyString& password);
	
	void logout();

	const Vector<ExternalCompanyEmployee>& getExternalEmployees() const;
	// get loggedUSER
	const Client* getLoggedClient() const;
	Client* getLoggedClient();

	const BankEmployee* getLoggedBankEmployee() const;
	BankEmployee* getLoggedBankEmployee();

	const ExternalCompanyEmployee* getLoggedExternalEmployee() const;
	ExternalCompanyEmployee* getLoggedExternalEmployee();

	//get type
	LoggedUserType getType() const;


	void save() const;

	void load();
	void exit();

};

