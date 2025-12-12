#pragma once
#include <iostream>
#include <string> 
#include <sstream> 
using namespace std;

class Human
{
public:
	Human(string last_name, string name, string second_name);
	~Human();
	virtual string toString();

private:
	string name; // имя 
	string last_name; // фамилия 
	string second_name; // отчество 

};

Human::Human(string last_name, string name, string second_name) : last_name(last_name), name(name), second_name(second_name)
{

}

Human::~Human()
{
}

string Human::toString()
{
	std::ostringstream full_name;
	full_name << this->last_name << " "
		<< this->name << " "
		<< this->second_name;
	return full_name.str();
}