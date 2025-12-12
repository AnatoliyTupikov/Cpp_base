#include <iostream>
#include <concepts>
#include <math.h>
using namespace std;

template <typename T>
concept Comparable = requires(T a, T b) {
	{ a < b } -> std::convertible_to<bool>;
	//{ a > b } -> std::convertible_to<bool>;
};

class Point
{
public:
	
	~Point();
	Point(int x, int y);
	double getDistance() const;

	bool operator< (const Point) const;

	int x;
	int y;

private:

};

Point::Point(int x, int y) :x(x), y(y)
{
}

Point::~Point()
{
}

double Point::getDistance() const
{
	return sqrt(x * x + y * y);
}

bool Point::operator< (const Point p) const
{
	return this->getDistance() < p.getDistance();
}


template <Comparable T>
T& maxOfTwo(T& a, T& b) { return a < b ? b : a; }

int main()
{
	Point p1(3, 4); // distance = 5
	Point p2(6, 8); // distance = 10
	cout << "Max of p1 and p2 is Point(" << maxOfTwo(p1, p2).x << ", " << maxOfTwo(p1, p2).y << ")" << endl;

	int a = 10, b = 7;
	
	cout << "Max of 3 and 7 is " << maxOfTwo(a, b) << endl;

	double d1 = 5.5, d2 = 3.3;
	cout << "Max of 5.5 and 3.3 is " << maxOfTwo(d1, d2) << endl;
	return 0;
}