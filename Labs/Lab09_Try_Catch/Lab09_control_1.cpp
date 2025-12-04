#include <iostream>
#include <string>
using namespace std;

class TriangleError : public exception
{
	private:
		int bad_side;
		int right_side;
		int right_side2;
		string message;


public:
	TriangleError(int bad_side, string massage, int right_side, int right_side2c)
	{
		this->bad_side = bad_side;
		this->right_side = right_side;
		this->right_side2 = right_side2c;
		this->message = massage;
	}

	int get_bad_side() const { return bad_side; }
	int get_right_side() const { return right_side; }
	int get_right_side2() const { return right_side2; }
	string get_message() const { return message; }
	
};

class Triangle
{
public:
	Triangle(int side1, int side2, int side3);
	~Triangle();

	double get_area();

private:
	int side1;
	int side2;
	int side3;
};

Triangle::Triangle(int side1, int side2, int side3)
{
	if (side1 + side2 <= side3) 
	{
		throw TriangleError(side3, "Invalid triangle side", side1, side2);
	}
	if (side1 + side3 <= side2) 
	{
		throw TriangleError(side2, "Invalid triangle side", side1, side3);
	}
	if (side2 + side3 <= side1) 
	{
		throw TriangleError(side1, "Invalid triangle side", side2, side3);
	}
	this->side1 = side1;
	this->side2 = side2;
	this->side3 = side3;

}

Triangle::~Triangle()
{
}

double Triangle::get_area(){
	double p = (side1 + side2 + side3) / 2.0;
	return sqrt(p * (p - side1) * (p - side2) * (p - side3));
}

int main() {
	try{
		Triangle t(3, 4, 8);
		cout << "Triangle area: " << t.get_area() << endl;
	}
	
	catch (TriangleError& e) {
		cout << e.get_message() << ": " << e.get_bad_side() << " is not valid side. It should be less than " << e.get_right_side() << " + " << e.get_right_side2() << endl;
	}
	

}