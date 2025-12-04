#include <string>
#include <iostream>

using namespace std;

class Student
{
public:
	void set_name(std::string student_name) {
		name = student_name;
	}

	std::string get_name() {
		return name;
	}

	void set_last_name(std::string student_last_name) {
		last_name = student_last_name;
	}

	std::string get_last_name() {
		return last_name;
	}

	void set_scores(const int student_scores[]) {
		for (int i = 0; i < 5; i++) {
			scores[i] = student_scores[i];
		}

	}

	void set_average_score(double ball) {
		average_score = ball;
	}

	double get_average_score() {
		return average_score;		
	}
	
	

private:

	std::string name;
	std::string last_name;
	double average_score;
	int scores[5];
};

void set_scores(const int scores[]) {
	scores = new int[5] {};
	
}

int main() {
    
	Student student01; // Create an object of the Student class in the stack

	string name;
	string last_name;
	int scores[5];

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

	student01.set_name(name);
	student01.set_last_name(last_name);
	student01.set_scores(scores);

	student01.set_average_score((double)(sum) / 5);

	cout << "Student: " << student01.get_name() << " " << student01.get_last_name() << endl;
	cout << "Average score: " << student01.get_average_score() << endl;
	return 0;


}