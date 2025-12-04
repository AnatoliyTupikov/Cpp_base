#include <string>
#include <iostream>
#include "student.h"
#include <Windows.h>

using namespace std;

// student class in student.h file

int main() {
    

	setlocale(LC_ALL, "ru");

	Student student01; //We can create an object of user's class in the stack. Will be deleted automatically when going out of scope, but in the stack there is less memory available
	

	string name;
	string last_name;
	int scores[5];

	SetConsoleCP(1251);

	cout << "Enter name: ";
	getline(cin, name);
	
	cout << "Enter last name: ";
	getline(cin, last_name);

	int sum = 0;
	for (int i = 0; i < 5; i++) {
		cout << "Enter score " << i + 1 << ": ";
		cin >> scores[i];
		sum += scores[i];
	}
	
	Student* student02 = new Student(name, last_name); 
	// Create an object of the Student class in the heap. Must be deleted manually using delete to avoid memory leaks, but in the heap there is more memory available

	student02->set_name(name); // оператор косвенного обращения, allow to not use *
	student02->set_last_name(last_name);
	student02->set_scores(scores);

	student02->set_average_score((double)(sum) / 5);

	cout << "Student: " << student02->get_name() << " " << student02->get_last_name() << endl;
	cout << "Average score: " << student02->get_average_score() << endl;

	delete student02; // !!!free memory allocated in the heap
	SetConsoleCP(866);
	return 0;


}