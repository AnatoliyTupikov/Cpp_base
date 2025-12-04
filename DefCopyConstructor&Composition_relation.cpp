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
	~SubClass() { cout << this << " is being deleted" << endl; };
};

class MyClass
{	
public:
	SubClass obj;
	MyClass(int data) : obj(data) {};
	~MyClass() { };

private:

};

void Foo(MyClass cl) //here copy constructor is called.
//copy of myObj is created on stack, because the function onbject is on the stack, so variable-distination for copy "cl" also is on the stack.
{
	//by composition relation reason, SubClass obj is part of MyClass: literally bytes of SubClass obj are inside MyClass object bytes.
	//Because of this SubClass obj is copied full, not only pointer to it.
	//Can say, in thiis case, default copy constructor makes deep copy of MyClass obj.
	cout << "Function copy SubClass:" << &cl.obj << endl;
} //here copy "cl" is destroyed, and its SubClass obj is also.

int main() 
{	
	MyClass* myObj = new MyClass(5); //heap allocation
	cout << "Original SubClass: " << &(myObj->obj) << endl;
	Foo(*myObj);
	delete myObj; 
	cout << "Program is closing..." << endl;


	return 0;
}