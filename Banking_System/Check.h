#pragma once
#include "Utilities/MyString.h"
class Check
{
private:
	MyString sender;
	MyString uniqueCode;
	unsigned cashToSend;
	MyString egn;
	bool isValidCode(const MyString& code);
	static int MAX_CODE_SIZE;
	
public:
	Check() = default;
	Check(const MyString& sender,const MyString& code,unsigned cashToSend,const MyString& egn);
	unsigned getCash() const;
	bool checkIfCodeIsRight(const MyString& code) const;
	const MyString& getCode() const;
	const MyString& getSender() const;
	const MyString& getEgn() const;
};

