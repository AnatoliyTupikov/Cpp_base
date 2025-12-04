#pragma once
#include <string>
#include <iostream>
#include "IdCard.h"
using namespace std;
class Student
{
	private:
	string name;
	int age;
	string last_name;
	IdCard* idCard; //Pointer to an object of IdCard class. Association relationship with IdCard class. 
	//That's mean that each Student object can have a pointer to an IdCard object. 
	//IDCard object can exist independently of Student object. And should be destroyed separately to avoid memory leaks.

	public:		
		Student(string student_name, string student_last_name, int student_age, IdCard* id)
			: name(student_name), age(student_age), last_name(student_last_name), idCard(id) {} //list initialization constructor
			
		~Student() 
		{cout << "Stdent: " << get_name() << " " << get_last_name() << " is being destroyed." << endl;} //destructor

		void set_name(string student_name);
		string get_name();
		void set_last_name(string student_last_name);
		string get_last_name();
		IdCard* getIdCard();
		void show();

};

void Student::set_name(std::string student_name) { name = student_name;}

string Student::get_name() {return name;}

void Student::set_last_name(std::string student_last_name) {last_name = student_last_name;}

string Student::get_last_name() { return last_name; }

IdCard* Student::getIdCard() { return idCard; };



void Student::show() 
{
	cout << "Student Name: " << name << " " << last_name << ", Age: " << age << endl;
	if (idCard != nullptr) // Check if idCard pointer is not null
	{
		cout << "IdCard:"  << idCard -> getNumber() << endl;
		cout << "Category: " << idCard-> getCategory() << endl;
	}
	else
	{
		cout << "No ID Card assigned." << endl;
	}
}

