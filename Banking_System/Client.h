#pragma once
#include "User.h"
#include "Pair.hpp"
#include "Bank.h"
#include "Bill.h"
#include "MyVector.hpp"
#include "OpenAccountTask.h"
#include "CloseAccountTask.h"
#include "ChangeAccountTaskApproved.h"
#include "ChangeAccountTaskNoValidated.h"
#include "ChangeAccountTaskValidated.h"
class OpenAccountTask;
class Task;
class Client :public User
{
	// Inherited via User
	Vector<MyString> msg;
	
	Vector<Bill> bankAccounts;
	Vector<Check> checks;
	
	int findCheckIndex(const MyString& code) const;
public:
	Client(const MyString& name, const MyString& egn, unsigned age, const MyString& password);

	void addCheck(const Check& check);
	void addBill(const Bill& bill);
	void removeBill(const MyString& bankName,unsigned accountID);
	const Bill& getBill(int index) const;
	Bill& getBill(int index);


	int findbankAccountIndex(const MyString& bankName, unsigned accountID) const;

	static void help();

	void check_avl(const MyString& bankName, unsigned accountNumber) const;
	Task* open(const MyString& bankName);
	Task* close(const MyString& bankName, unsigned accountNumber);

	void redeem(const MyString& bankName, unsigned accountNumber, const MyString& verificationCode);

	Task* change(const MyString& newBankName,const MyString& currentBankName,unsigned accountNumber);
	void list(const MyString& bankName) const;
	void messages() const;
	void addMessage(const MyString& message);
};

