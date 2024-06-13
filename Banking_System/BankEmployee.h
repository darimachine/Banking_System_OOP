#pragma once
#include "MyVector.hpp"
#include "Task.h"
#include "User.h"
#include "PolyMorphic_Ptr.hpp"
class BankEmployee : public User
{
	Vector<PolymorphicPtr<Task>> tasks;


public:
	void addTask(Task* task);
};

