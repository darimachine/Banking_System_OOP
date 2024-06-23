#pragma once
#include "../Utilities/MyString.h"
#include "../Utilities/MyVector.hpp"
#include "../Check.h"
#include <fstream>
class User
{
	static int EGN_MAX_CHAR;
	static int MAX_AGE;
protected:
	MyString name;
	//MyString surName;
	MyString EGN;
	unsigned age;
	
	MyString password;

public:
	User() = default;
	User(const MyString& name, const MyString& egn, unsigned age, const MyString& password);
	
	void setName(const MyString& name);
	void setEGN(const MyString& egn);
	void setAge(unsigned age);
	void setPassword(const MyString& password);

	bool isValidPassword(const MyString& pw) const;

	const MyString& getName() const;
	unsigned getAge() const;
	const MyString& getEGN() const;

	void saveToFile(std::ofstream& ofs) const;

	void readFromFile(std::ifstream& ifs);
	
	void exit() const;
	void whoami() const;
	static void help();
};

