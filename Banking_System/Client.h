#pragma once
#include "User.h"
#include "Pair.hpp"
#include "Bank.h"
#include "Bill.h"
#include "MyVector.hpp"
class Client :public User
{
	// Inherited via User
	Vector<MyString> msg;
	
	Vector<Bill> bankAccounts;
	Vector<Check> checks;
public:
	Client(const MyString& name, const MyString& egn, unsigned age, const MyString& password);

	void addCheck(const Check& check);
	void addBill(const Bill& bill);


	void check_avl(const MyString& bankName, const MyString& accountNumber) const;
	void open(const MyString& bankName) const;
	void close(const MyString& bankName, const MyString& accountNumber) const;
	void redeem(const MyString& bankName, const MyString& accountNumber, const MyString& verificationCode);
	void change(const MyString& newBankName);
	void list(const MyString& bankName) const;
	void messages() const;
	void addMessage(const MyString& message);
};

