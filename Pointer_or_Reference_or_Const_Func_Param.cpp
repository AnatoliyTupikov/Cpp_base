
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

void FooConstant(const int& param, const int* const Pparam, const int ar[])
{
	//it's a function with constant parameter.
	//We can't change the value of the variable passed by reference directly without dereference.
	param = 40; //const int& param
	Pparam = nullptr; //const int* const Pparam OR int const* const Pparam
	ar[0] = 3; //const int ar[]
	ar = new int[3]; //"const int ar[]" doesn't protect the pointer itself. For that we need "const int* const ar"

}

void main()
{
	
	
}