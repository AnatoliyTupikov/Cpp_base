#include<iostream>;



void main()
{
	{ //mechanism of pointer and dereference operator(*)
		std::cout << "=============Pointer and Dereference operator example=============" << std::endl;

		int a = 5;
		int* px = &a; // here &a is "address-of operator" that give the address of "a" variable value

		std::cout << "Link of a: " << px << std::endl; //print the address of "a" variable

		//px = a; erro compilation because px is pointer(*int) and "a" is int;

		//For getting the value of "a" using pointer we need to use "dereference operator(*)":

		std::cout << "Value of a using pointer: " << *px << std::endl;

		//to change the value of "a" using pointer we also use the operator(*):
		*px = 10; //now the value of "a" is 10 and variable "a" is 10 too now.

		std::cout << std::endl;
	}

	{ //null value pointer
		std::cout << "=============Pointer with null=============" << std::endl;
		// pointers can also have a special value called "null pointer" which indicate that the pointer is not pointing to any valid memory address.

		int* pnull = nullptr; //nullptr is a special value that indicate that the pointer is not pointing to any valid memory address.
		std::cout << "Null pointer value: " << pnull << std::endl; //here it will print 0 or some implementation-defined value indicating that the pointer is null.

		//dereferencing a null pointer leads to undefined behavior, so we should always check if a pointer is null before dereferencing it.
		std::cout << "Trying to dereferenc null pointer pointer:" << *pnull << std::endl; //here it just nothing. But in real code it may lead to crash or undefined behavior.

		//correct way to handle null pointer dereference:
		if(pnull == nullptr)
		{
			std::cout << "Pointer is null, cannot dereference it." << std::endl;
		}
		

		

		std::cout << std::endl;
	}


}