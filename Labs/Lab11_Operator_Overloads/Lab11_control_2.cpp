#include <iostream> 
#include <ostream>
#include <string> 
#include <vector> 
#include <algorithm> 
#include <cmath>
using namespace std;

class Point
{
public:
	Point();
	Point(int x, int y);
	~Point();

	double get_distance() const;

	bool operator< (Point p)const;

	friend ostream& operator<< ( ostream& out, const Point& p);

private:
	int x;
	int y;
};

Point::Point() : x(0), y(0){}

Point::Point(int x, int y) : x(x), y(y) {}

Point::~Point(){}

double Point::get_distance() const { return sqrt(x * x + y * y); }

bool Point::operator< (Point p)const { return this->get_distance() < p.get_distance(); }

ostream& operator<< (ostream& out, const Point& p) 
{
	return out << "X: " << p.x << " Y: " << p.y << " Distance: " << p.get_distance();
}

int main()
{
	std::vector<Point> v;
	v.push_back(Point(1, 2));
	v.push_back(Point(10, 12));
	v.push_back(Point(21, 7));
	v.push_back(Point(4, 8));
	std::sort(v.begin(), v.end()); // требуется перегрузка оператора < для 
	// класса Point 
	for (auto& point : v)
		std::cout << point << '\n'; // требуется перегрузка оператора << для 
	// класса Point 
	return 0;
}