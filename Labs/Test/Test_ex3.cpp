


class Point {
	int x, y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}
	Point operator+ (const Point& p) const {
		Point temp;
		temp.x = x + p.x;
		temp.y = y + p.y;
		return temp;
	}
	friend Point operator+ (const Point& p, int k);
	Point& operator+= (const Point& p) {
		x += p.x;
		y += p.y;
		return *this;
	}
};

Point operator+ (const Point& p, int k) {
	Point temp;
	temp.x = p.x + k;
	temp.y = p.y + k;
	return temp;
}

int main()
{

	Point pt1(1, 1), pt2(2, 2), pt3;
	pt3 = pt1 + pt2;
	pt2 += pt1;
	pt3 = pt1 + 5;




	return 0;
}