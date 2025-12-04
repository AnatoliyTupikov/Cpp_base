#include "Triangle.h"

Triangle::Triangle(Dot dot1, Dot dot2, Dot dot3)
{
	if (!&dot1 || !&dot2 || !&dot3)
	{
		throw TriangleError(0, "Null pointer exception", 0, 0);
	}
	side1 = dot1.distanceTo(dot2);
	side2 = dot2.distanceTo(dot3);
	side3 = dot3.distanceTo(dot1);
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
	this->dot1 = &dot1;
	this->dot2 = &dot2;
	this->dot3 = &dot3;

}

Triangle::~Triangle()
{
}


double Triangle::get_perimiter() {

	return  side1 + side2 + side3;
}

double Triangle::get_area() {

	double p = (side1 + side2 + side3) / 2.0;
	return sqrt(p * (p - side1) * (p - side2) * (p - side3));
}

void Triangle::show() {
	cout << "Triangle vertices: " << endl;
	cout << "Sides: " << side1 << ", " << side2 << ", " << side3 << endl;
	cout << "Perimeter: " << get_perimiter() << endl;
	cout << "Area: " << get_area() << endl;
}