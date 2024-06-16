#pragma once
#include "MyVector.hpp"
#include "Task.h"
#include "User.h"
#include "PolyMorphic_Ptr.hpp"
class BankEmployee : public User
{
	Vector<PolymorphicPtr<Task>> tasks;
	MyString bankAssociated;

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

