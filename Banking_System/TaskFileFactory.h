#pragma once
#include "Tasks/Task.h"
class TaskFileFactory
{
	static void saveChangeTask(std::ofstream& ofs, const Task* task);
	static void saveRegularTask(std::ofstream& ofs, const Task* task);
public:
	static void saveTask(std::ofstream& ofs, const Task* task);
};

