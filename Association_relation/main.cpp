#include "IdCard.h"
#include "Student.h"
#include <string>
int main() {

	
	IdCard* card = new IdCard(98765, "STUDENT");
	Student* alice = new Student("Alice", "Val", 20, card );

	Student* mark = new Student("Mark", "Emmit", 23, nullptr); //we can create a student without an ID card

	delete alice; //this doesn't delete the IdCard, because the association relationship
	delete mark;

	delete card; //we need to delete the IdCard separately
	return 0;

}