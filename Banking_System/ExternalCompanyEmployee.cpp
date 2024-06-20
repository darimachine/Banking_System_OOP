#include "ExternalCompanyEmployee.h"
#include "Check.h"
ExternalCompanyEmployee::ExternalCompanyEmployee(const MyString& name, const MyString& egn, unsigned age, const MyString& password)
	:User(name,egn,age,password)
{

}

Check& ExternalCompanyEmployee::sendCheck(double sum, const MyString& code, const MyString& egn)
{

	Check checkToSend(name,code, sum,egn);
	return checkToSend;
}
