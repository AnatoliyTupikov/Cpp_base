#pragma once
#include <iostream>
#include <string>
#include "Dot.h"
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
	
	Triangle(Dot dot1, Dot dot2, Dot dot3);

	~Triangle();

	double get_area();
	double get_perimiter();
	double get_side1() { return side1; }
	double get_side2() { return side2; }
	double get_side3() { return side3; }
	void show();

private:
	Dot* dot1;
	Dot* dot2;
	Dot* dot3;

	double side1;
	double side2;
	double side3;

};


