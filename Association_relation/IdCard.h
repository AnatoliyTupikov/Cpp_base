#pragma once
#include <string> 
#include <iostream>
using namespace std;
class IdCard
{
private:
	int number;
	string category;
public:
	IdCard();
	IdCard(int);
	IdCard(int, string);
	~IdCard() {	cout << "IdCard with number " << number << " is being destroyed." << endl; }

	void setNumber(int newNumber);
	int getNumber();
	void setCategory(string cat);
	string getCategory();	
	
};


IdCard::IdCard(int n)
{
	number = n;
	category = "Не установлена";
}
IdCard::IdCard()
{
	number = 0;
	category = "Не установлена";
}
IdCard::IdCard(int n, string cat)
{
	number = n;
	category = cat;
}

void IdCard::setNumber(int newNumber)
{
	number = newNumber;
}
int IdCard::getNumber()
{
	return number;
}
void IdCard::setCategory(string cat)
{
	category = cat;
}
string IdCard::getCategory()
{
	return category;
}