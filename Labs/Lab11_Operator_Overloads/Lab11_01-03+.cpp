#include <iostream>
#include <ostream>
using namespace std;

class Distance
{
	private:
		int feet;
		float inches;
		float MTF = 3.280833F;
	public:
		// конструктор по умолчанию 
		Distance() : feet(0), inches(0.0) {}
		// конструктор с двумя параметрами 
		Distance(int ft, float in) : feet(ft), inches(in){}
		void getdist()
		{
			cout << "\nВведите число футов : ";
			cin >> feet;
			cout << "\nВведите число дюймов : ";
			cin >> inches;
		}
		Distance(float meters) //это конструктор с одним параметром он и есть оператор преобразования из float (метры) в Distance
		{
			float fltfeet = MTF * meters;
			feet = int(fltfeet);		
			inches = 12 * (fltfeet - feet);
		}

		explicit operator float() const; // оператор обратного преобразования из Distance в float (метры), но уже явный
		
		
		Distance operator+ (const Distance&) const; // const чтобы не изменять исходный объект this, обязательно в данном случае, т.к. есть оператор неявного преобразования
		Distance operator+ (float) const;	
		Distance operator- (const Distance&) const;
		Distance operator- (float) const;
		
		
		friend Distance operator+ (float, const Distance&);	
		friend Distance operator- (float, const Distance&);	
		
		friend ostream& operator<< (std::ostream& out, const Distance& dist);
};

Distance:: operator float() const 
{
	float fracfeet = inches / 12;
	fracfeet += static_cast<float>(feet);
	return fracfeet / MTF;
}

Distance Distance::operator+ (const Distance& d2) const // сложение двух расстояний
{
	int f = feet + d2.feet;
	float i = inches + d2.inches;
	if (i >= 12.0)
	{
		i -= 12.0;
		f++;
	}
	return Distance(f, i);
}

Distance Distance::operator+ (float meters) const // сложение объекта Distance и flaot (метры) (именно в таком порядке)
{
	Distance d2 = meters; // неявное преобразование из float в Distance
	return *this + d2; // использование определенного выше оператора +
}

Distance Distance::operator- (const Distance& d2) const// вычитание двух расстояний
{
	float res = ((float)this->feet * 12 + this->inches) - ((float)d2.feet * 12 + d2.inches);
	if (res <= 0) return Distance();
	int foot = (int)res / 12;
	float inches = res - 12 * foot;
	return Distance(foot, inches);

}

Distance Distance::operator- (float meters) const // вычетание из объекта Distance значения flaot (метры)
{
	Distance d2 = meters; 
	return *this - d2; // использование определенного выше оператора -
}

Distance operator+ (float meters, const Distance& dist) // сложение float (метры) и объекта Distance (именно в таком порядке)
{
	Distance d1 = meters; 
	return d1 + dist; 
}

Distance operator- (float meters, const Distance& dist) // вычетание из float (метры) объекта Distance
{
	Distance d1 = meters;
	return d1 - dist;
}


ostream& operator<< (std::ostream& out, const Distance& dist) // вывод расстояния
{
	return out << dist.feet << "\'- " << dist.inches << "\"\n";
}


int main()
{
	Distance dist1, dist2, dist3, dist4;
	dist1 = 2.25; // неявное преобразование из float в Distance
	float mtrs = (float)dist1; // явное преобразование из Distance в float
	cout << "\ndist1 = " << mtrs << "meter(s)" << endl;
	dist2.getdist();

	dist3 = dist1 - dist2;
	dist4 = dist1 - dist2 - dist3;
	dist4 = dist4 + 2.0;
	dist4 = 2.0 + dist4;
	dist4 = dist4 - 4.0;
	dist4 = 4.0 - dist4;

	cout << "\ndist1 = " << dist1;
	//dist1.showdist();
	cout << "\ndist2 = " << dist2;
	//dist2.showdist();
	cout << "\ndist3 = " << dist3;
	//dist3.showdist();
	cout << "\ndist4 = " << dist4;
	//dist4.showdist();
	return 0;
}