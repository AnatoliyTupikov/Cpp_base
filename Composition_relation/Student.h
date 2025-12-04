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
	IdCard idCard; // Composition relationship with IdCard class. By this reason, constructor of IdCard will be called first before Student constructor.
	//The IdCard object will be created and store inside Student object. Literally, bytes of IdCard object will be part of bytes of Student object.

	public:		
		//In this case, always the DEFAULT constructor of IdCard will be called before Student constructor.
		Student(string student_name, string student_last_name, int student_age)
			: name(student_name), age(student_age), last_name(student_last_name) 
		{
			cout << "Student constructor called" << endl;
			setIdCard(-1, "UNKNOWN"); // Here we create another IdCard object, 
			//becase even before Student constructor is called, the default constructor of IdCard was already called. And it created an IdCard object with default values and assigned it to idCard member of Student class.
									
		} 

		//If you want to call a specific constructor of IdCard, you must do it in the initialization list of Student constructor.
		Student(string student_name, string student_last_name, int student_age, int idcard, string idcardCategory)
			: name(student_name), age(student_age), last_name(student_last_name), idCard(idcard, idcardCategory)
		{
			cout << "With specifc IDCard student constructor called" << endl;
			
		}

			
		~Student() 
		{cout << "Stdent: " << get_name() << " " << get_last_name() << " is being destroyed." << endl;} //destructor

		void set_name(string student_name);
		string get_name();
		void set_last_name(string student_last_name);
		string get_last_name();
		
		void setIdCard(int id, string c);
		int getIdCard();
		void show();
};


void Student::set_name(std::string student_name) { name = student_name;}

string Student::get_name() {return name;}

void Student::set_last_name(std::string student_last_name) {last_name = student_last_name;}

string Student::get_last_name() { return last_name; }

void Student::setIdCard(int id, string c)
{
	// Set fields of the existing IdCard object.

	/*idCard.setNumber(id);
	idCard.setCategory(c);*/

	idCard = IdCard(id, c); // Create a new IdCard object and assign it to the existing idCard member.
	// Old IdCard object will be destroyed automatically right after this line, if no other references to it exist.
}

int Student::getIdCard()
{
	return idCard.getNumber();
}



void Student::show() 
{
	cout << "Student Name: " << name << " " << last_name << ", Age: " << age << endl;
	cout << "IdCard:"  << idCard.getNumber() << endl;
	cout << "Category: " << idCard.getCategory() << endl;
	
	
}

