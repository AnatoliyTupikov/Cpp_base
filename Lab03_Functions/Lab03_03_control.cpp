

#include <iostream>

bool IsTriangleExist(double a, double b, double c)
{
    return (a + b > c) && (a + c > b) && (b + c > a);
}

double TriangleSquare(double a, double b, double c)
{
    if (!IsTriangleExist(a, b, c))
    {
        std::cerr << "Triangle with sides " << a << ", " << b << ", " << c << " does not exist.\n";
        return -1.0;
    }
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double TriangleSquare(double a)
{
	return TriangleSquare(a, a, a);
}



int main()
{
    int isEquilateral{0};
    std::cout << "A triangl is equilateral (0 - No, 1 - Yes): ";
    std::cin >> isEquilateral;
	
    if(isEquilateral)
    {
        
     std::cout << "Specify a triangle's side-> ";
     int side;
     std::cin >> side;
     double square = TriangleSquare(side);
     std::cout << "Equilateral triangle square with side " << side << " is " << square << "\n";
     
	 
    }
    else
    {
        int a, b, c;
        std::cout << "Specify a triangle's sides:";
        std::cout << "\na -> ";
        std::cin >> a;
        std::cout << "\nb -> ";
        std::cin >> b;
        std::cout << "\nc -> ";
        std::cin >> c;
        double square = TriangleSquare(a, b, c);
        if (square != -1.0)
        {
            std::cout << "Triangle square with sides " << a << ", " << b << ", " << c << " is " << square << "\n";
        }
        
    }
	return 0;
	
    
    
}

