#include<iostream>;

// Function Template Example. 
template<typename T> //Here is the template declaration. T is a placeholder for data type.
// We can add only one function template for a template declaration.
T Foo(T a, T b)
{
	return (a + b);
}

template<typename T1, typename T2> //We can use some different data types using multiple template parameters.
void Foo2(T1 a, T2 b) //We can also use different data types in function parameters or a return type. 
{
	std::cout << (a + b);
}

template<class T> //We can also use 'class' keyword instead of 'typename' keyword. It's comletely the same.
T Foo3(T a, T b)
{
	return (a + b);
}


void main()
{
	Foo2(1L, 2L); //Here T1 is long and T2 is also long. It's ok and works fine.


}