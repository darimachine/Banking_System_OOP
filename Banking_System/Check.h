#pragma once
#include "MyString.h"
class Check
{
private:
	MyString uniqueCode;
	unsigned cashToSend;
	void generateUniqueCheck();
	void makeUniqueTime();
	
public:
	Check() = default;
	Check(unsigned cashToSend);
	unsigned getCash() const;
};

