#pragma once
#include "human.h"
#include <string> 

class Teacher : public Human
{
public:
	Teacher(std::string last_name, std::string name, std::string second_name, unsigned int work_time);
	~Teacher();
	unsigned int get_work_time();
	string toString() override;

private:
	unsigned int work_time;
};

Teacher::Teacher(std::string last_name,	std::string name, std::string second_name, unsigned int work_time) : Human(	last_name, name, second_name)
{
	this->work_time = work_time;
}

Teacher::~Teacher()
{
}

unsigned int Teacher::get_work_time()
{
	return this->work_time;
}

string Teacher::toString()
{
	std::ostringstream full_info;
	full_info << Human::toString() << ", рабочих часов: " << this->get_work_time();
	return full_info.str();
}


