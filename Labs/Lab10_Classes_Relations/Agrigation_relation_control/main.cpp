#include <iostream>
#include "Dot.h"
#include "Triangle.h"
using namespace std;

int main() {

	Dot d1(1, 2);
	Dot d2(4, 6);
	Dot d3(7, 2);
	Triangle t(d1, d2, d3);
	t.show();
}