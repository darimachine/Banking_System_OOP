#pragma once
#include "../Utilities/MyString.h"
#include "../Tasks/Task.h"
#include "User.h"
#include "../Utilities/PolyMorphic_Ptr.hpp"
class BankEmployee : public User
{
	Vector<PolymorphicPtr<Task>> tasks;
	MyString bankAssociated;
	bool isValidTaskID(unsigned taskID) const;
public:
	BankEmployee() = default;
	BankEmployee(const MyString& name, const MyString& egn, unsigned age, const MyString& password,const MyString& bankAssociated);
	void addTask(Task* task);
	void showTasks() const;
	void removeTask(unsigned id);

	unsigned getTaskCount() const;
	const MyString& getBankAssociated() const;

	void view(unsigned taskID) const;
	Task* approve(unsigned taskID);
	void disapprove(unsigned taskID, const MyString& message);
	Task* validate(unsigned taskID);
	static void help();
};

