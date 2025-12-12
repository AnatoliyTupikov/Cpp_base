#include <vector>
#include"human.h"
#include"student.h"
#include"teacher.h"

int main()
{
	// Оценкистудента 
	vector<int> scores;
	// Добавление оценок студента в вектор 
	scores.push_back(5);
	scores.push_back(3);
	scores.push_back(4);
	scores.push_back(4);
	scores.push_back(5);
	scores.push_back(3);
	scores.push_back(3);
	scores.push_back(3);
	scores.push_back(3);

	
	vector<Human*> humans;
	Student* stud1 = new Student("Петров", "Иван", "Алексеевич", scores);	
	Student* stud2 = new Student("Иванов", "Петр", "Алексaндрович", scores);	
	Teacher* tch1 = new Teacher("Сергеев", "Дмитрий", "Сергеевич", 40);
	Teacher* tch2= new Teacher("Конюхов", "Алексей", "Иванович", 53);
	humans.push_back(stud1);
	humans.push_back(stud2);
	humans.push_back(tch1);
	humans.push_back(tch2);

	for (unsigned int i = 0; i < humans.size(); ++i) {
		cout << humans[i]->toString() << endl;
	}



	

	delete stud1;
	delete stud2;

	delete tch1;
	delete tch2;
	
	return 0;
}