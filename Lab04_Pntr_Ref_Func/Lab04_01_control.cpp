#include<iostream>;

 
int Foo(double a, double b, double c, double& x1, double& x2 )
{
	if (a == 0 || b == 0 || c == 0)
		return -1;
	double D = b * b - 4 * a * c;
	if (D < 0)
		return 1;
	else if (D == 0)
	{
		x1 = -b / (2 * a);
		x2 = x1;
		return 0;
	}
	else
	{
		x1 = (-b + sqrt(D)) / (2 * a);
		x2 = (-b - sqrt(D)) / (2 * a);
		return 1;
	}
}




void main()
{
	double x1, x2;
	int res = Foo(0, -3, 2, x1, x2);

	if (res == 1)
		std::cout << "Two roots: " << x1 << ", " << x2 << std::endl;
	else if (res == 0)
		std::cout << "One root: " << x1 << std::endl;
	else
		std::cout << "No real roots" << std::endl;

}