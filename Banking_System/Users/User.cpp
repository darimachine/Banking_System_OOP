#include "User.h"

int User::EGN_MAX_CHAR = 10;
int User::MAX_AGE = 150;
using std::cout;
using std::endl;
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
		throw std::invalid_argument("Invalid Name It must contain Only Letters");
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
	cout << "Succesfully exited\n";
}

const MyString& User::getName() const
{
	return name;
}

void User::whoami() const
{
	cout << "You are " << name<<endl;
}

unsigned User::getAge() const
{
	return age;
}

bool User::isValidPassword(const MyString& pw) const
{
	return password==pw;
}

void User::help()
{
}

const MyString& User::getEGN() const
{
	return EGN;
}
void User::saveToFile(std::ofstream& ofs) const {
	name.saveToFile(ofs);
	EGN.saveToFile(ofs);
	ofs.write((const char*)&age, sizeof(age));
	password.saveToFile(ofs);

}
void User::readFromFile(std::ifstream& ifs) {
	name.readFromFile(ifs);
	EGN.readFromFile(ifs);
	ifs.read((char*)&age, sizeof(age));
	password.readFromFile(ifs);
}


