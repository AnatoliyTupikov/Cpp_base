#include "IdCard.h"
#include "Student.h"
#include <string>
int main() {

	
	//IdCard* card = new IdCard(98765, "STUDENT"); we don't need to create an IdCard separately anymore
	Student* alice = new Student("Alice", "Val", 20); //in composition relationship, the Student creates and owns the IdCard
	
	alice->show();

	delete alice; //this doesn't delete the IdCard, because the association relationship

	
	return 0;

}