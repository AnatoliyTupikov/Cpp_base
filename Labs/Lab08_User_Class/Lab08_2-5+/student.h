/* student.h */ 
#pragma once /* это инструкция для компилятора, означающая: «Включать этот заголовочный файл только один раз при компиляции». */ 
#include <string> 
using namespace std;

class Student
{
public:

	// realizations of next methods in student.cpp
	Student();
	Student(string, string);

	void set_name(string);
	string get_name();
	void set_last_name(string);
	string get_last_name();
	void set_scores(const int[]);
	void set_average_score(double);
	double get_average_score();
	void save();

	~Student();



private:

	std::string name;
	std::string last_name;
	double average_score;
	int scores[5];
};


