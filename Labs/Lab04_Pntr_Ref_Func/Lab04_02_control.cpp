#include<iostream>;

bool Input(int& a, int& b) 
{
	std::cout << "Enter two integers: ";
	std::cout << "The specified numbers must satisfy the following condition: a < b" << std::endl;
	std::cout << "Specify the a ->";
	if (!(std::cin >> a)) return false;
	std::cout << "Specify the b ->";
	if (!(std::cin >> b)) return false;
	if (a >= b) return false;
	return true;

}
int main()
{
	int a, b;
	if (Input(a, b) == false) // if(!Input(a,b)) 
	{

		std::cerr << "error";
		return 1;
	}
	int s = a + b;
	return 0;
	
}