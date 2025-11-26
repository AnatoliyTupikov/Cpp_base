
#include <iostream>

void Foo(int param)
{
	//it's a just function. 
	// Local copy of param variable is created here.
	param = 20;
}

void FooPointer(int* param)
{
	//it's a function with pointer parameter. 
	//We can change the value of the variable passed by address via dereference.
	*param = 30;
	//Or can work on the pointer itself (Pointer arithmetic)
	*(param + 1);
	param + 1;

}

void FooReference(int& param)
{
	//it's a function with reference parameter.
	//We can change the value of the variable passed by reference directly without dereference.
	param = 40;
}

void main()
{

	
}