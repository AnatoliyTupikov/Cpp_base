#include <string>
#include <fstream>
#include "student.h" // include the header file
using namespace std;

//============constructors for class Student============

Student::Student() : name("name"), last_name("last_name"), average_score(0.0) // initializer list the same as commented strings in body of constructor below
{
	//Student::set_name("name");
	//Student::set_last_name("last_name");
	
	//More dificult initializations can't be done in initializer list, so we do them in body of constructor
	int default_scores[5] = { 0,0,0,0,0 };
	set_scores(default_scores);
}

Student::Student(string name, string last_name)
{
	Student::set_name(name);
	Student::set_last_name(last_name);
}

//============method realizations for class Student============

void Student::set_name(std::string student_name) { //before adding a metod realizatoin for a class, in another file, you need to specify prototype in the class view (header file)
	name = student_name;
}

string Student::get_name() {
	return name;
}

void Student::set_last_name(std::string student_last_name) {
	last_name = student_last_name;
}

string Student::get_last_name() {
	return last_name;
}

void Student::set_scores(const int student_scores[]) {
	for (int i = 0; i < 5; i++) {
		scores[i] = student_scores[i];
	}

}

void Student::set_average_score(double ball) {
	average_score = ball;
}

double Student::get_average_score() {
	return average_score;
}

void Student::save() {

	ofstream fout("students.txt", ios::app); // open file in append mode
	if (fout.is_open()) {
		
		fout << Student::get_name() << " " << Student::get_last_name() << " ";
		for (int i = 0; i < 5; i++) {
			fout << scores[i] << " ";
		}
		fout<< endl;
		fout.close();
	}
	
}

//============destructor for class Student============
Student::~Student()
{
	Student::save();
}