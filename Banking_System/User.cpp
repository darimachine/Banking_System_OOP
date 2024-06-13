#include "User.h"
int User::EGN_MAX_CHAR = 10;
int User::MAX_AGE = 150;
static bool checkIfIsLetter(const char ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
	{
		return true;
	}
	return false;
}
static bool validateOnlyLetters(const MyString& name)
{
	unsigned size = name.getSize();
	for (int i = 0; i < size; i++)
	{
		if (!checkIfIsLetter(name[i]))
		{
			return false;
		}
	}
	return true;

}

User::User(const MyString& name, const MyString& egn, unsigned age, const MyString& password)
{
	setName(name);
	setEGN(egn);
	setAge(age);
	setPassword(password);
}

void User::setName(const MyString& name)
{
	if (!validateOnlyLetters(name)) {
		throw std::invalid_argument("Its not letter");
	}
	this->name = name;

}

void User::setEGN(const MyString& egn)
{
	if (egn.getSize() != EGN_MAX_CHAR || validateOnlyLetters(egn))
	{
		throw std::invalid_argument("Invalid EGN");
	}
	this->EGN = egn;
}

void User::setAge(unsigned age)
{
	if (age > MAX_AGE)
	{
		throw std::invalid_argument("Invalid Age");
	}
	this->age = age;
}

void User::setPassword(const MyString& password)
{
	this->password = password;
}

void User::exit() const
{
}

const MyString& User::getName() const
{
	return name;
}

void User::whoami() const
{
}

unsigned User::getAge() const
{
	return age;
}

void User::help() const
{
}

const MyString& User::getEGN() const
{
	return EGN;
}


