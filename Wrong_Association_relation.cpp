#include <iostream>
#include <string>
#include <fstream> 

#include <sstream>
#include <thread>
#include <chrono>
using namespace std;

class SubClass
{	
	public:
	int data;
	SubClass(int data) { this->data = data; };
	~SubClass() { cout << this << " is being deleted"; };
};

class MyClass
{

	SubClass* obj;
public:
	MyClass(SubClass* obj) { this->obj = obj; };
	~MyClass() { delete obj; }; 
	//With association relation, we should not delete the associated object in destructor of main class.
	//Because it may to lead to the next problems:

};

int main() 
{
	SubClass subObj(10); //stack allocation
	MyClass* myObj = new MyClass(&subObj); //heap allocation
	delete myObj; // Crushes here because subObj is deleted in MyClass destructor.But subObj is stack allocated and can't be deleted by "delete" operator.
	//But it's happened because delete in MyClass destructor.
	cout << "Program is closing..." << endl;


	return 0;
}