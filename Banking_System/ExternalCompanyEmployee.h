#pragma once
#include "User.h"
class Check;
class ExternalCompanyEmployee : public User
{
public:
	ExternalCompanyEmployee(const MyString& name, const MyString& egn, unsigned age, const MyString& password);
	Check& sendCheck(double sum, const MyString& code, const MyString& egn);
};

