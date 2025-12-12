#include<map>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct StudentsGrades 
{
	map<string, char> grades;
public:
	StudentsGrades();
	void showList() const;
	bool addStudent();
	void changeGrade();

};

StudentsGrades::StudentsGrades() 
{
	grades = {};
}

void StudentsGrades::showList() const 
{
	if (grades.size() == 0) cout << "Nothing to show!" << endl;
	for_each(grades.cbegin(), grades.cend(), // const iterators
		[](const pair<string, char>& stud) { // lambda function
			cout << stud.first << " has the next grade: " << stud.second << endl;
		});
}

bool StudentsGrades::addStudent()
{
	cout << "Specify student's name and grade: ";
	string stud;
	char grade;

	cin >> stud;
	cin >> grade;

	if (!grades.emplace(stud, grade).second)
	{
		cout << "The student already excists in the journal!" << endl; 
		return false;
	}

	cout << "\tDone!" << endl;
	return true;
}

void StudentsGrades::changeGrade() 
{
	cout << "For changing a grade of a studen, specify the sudent's name from the journal: ";
	string stud;
	cin >> stud;

	if (grades.find(stud) == grades.end()) // find() returns iterator to end() if not found
	{
		cout << "The student doesn't excist in the journal!" << endl;
		return;
	}
	

	cout << "\tSpecify grade for the student: ";
	char grade;	
	cin >> grade;
	grades[stud] = grade;

	cout << "\tDone!" << endl;

}

int main()
{

	cout << "How many students' grades do you want to add to the journal? ";
	int n;
	cin >> n;
	StudentsGrades sg;
	for (int i = 0; i < n; ++i) 
	{
		if (!sg.addStudent()) --i;		
	}

	sg.showList();

	bool isFirst = true;
	do
	{
		char command;
		cout << "Do you want to change a grade of a student? (y/n): ";
		cin >> command;
		command = tolower(command);
		if (command == 'n') 
		{
			if(!isFirst) sg.showList();
			break;
		}
		else if (command == 'y') 
		{
			sg.changeGrade();
			isFirst = false;
		}
		else 
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear input buffer
			cout << "Unknown command!" << endl;
		}
		

	} while (true);
	
	return 0;
}