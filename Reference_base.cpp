#include <iostream>
int main()
{
	{// Reference base. Example of pointer vs reference.
		int a = 10;

		int* pa = &a; // pa is a pointer to a
		std::cout << "Value of a using pointer: " << pa << std::endl; // here we get the address of "a" value

		int& aref = a; // ref is a reference to a
		std::cout << "Value of a using reference: " << aref << std::endl; // here we get the value of "a" directly without any dereferencing
		//The main difference between pointers and references is that references not require dereferencing to access the value they refer to, while pointers do.
		// The reference doen't give the access to the address of the variable it refers to and work on it.
		//References are often used to create aliases for variables, making code more readable and easier to work with.

	}

	{// Reference can't be null
		int a = 20;
		//int& ref = nullptr; // This will cause a compilation error because references must be initialized to refer to a valid object.
		//int& ref; // Or this will also cause a compilation error because references must be initialized when they are declared.
		int& ref = a; // Correct usage
		std::cout << "Value of a using reference: " << ref << std::endl;

	}

	{// Reference can't change the object it refers to
		int a = 30;
		int b = 40;
		int& ref = a; // ref refers to a
		std::cout << "Initial value of ref: " << ref << std::endl; // Outputs 30
		ref = b; // This does not make ref refer to b; instead, it assigns the value of b to a.
		std::cout << "Value of a after assigning b to ref: " << a << std::endl; // Outputs 40
		std::cout << "Value of ref after assigning b to ref: " << ref << std::endl; // Outputs 40

	}

	{// We can get the address of a reference
		int a = 50;
		int& ref = a;
		std::cout << "Address of a: " << &a << std::endl;
		std::cout << "Address of ref: " << &ref << std::endl; // Both addresses will be the same
		int* pRef = &ref; // Getting the address of the reference, but here pRef doesn't store the address of the reference itself, but the address of the variable it refers to.
		std::cout << "Address stored in pRef: " << pRef << std::endl; // This will also be the address of a

	}
	
}