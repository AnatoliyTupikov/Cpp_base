// перевод длины из класса Distance в метры и обратно
#include <iostream>

using namespace std;

class Distance	// класс английских мер длины
{
private:
	const float MTF;     // коэффициент перевода метров в футы
	int feet;
	float inches;

public:
	// конструктор без параметров
	Distance() : feet(0), inches(0.0), MTF(3.280833F) { cout << "\nctor um\n"; }

	// конструктор с одним параметром, переводящий метры в футы и дюймы
	Distance(float meters) : MTF(3.280833F)
	{
		float fltfeet = MTF * meters;      // переводим в футы
		feet = int(fltfeet);				// берем число полных футов
		inches = 12 * (fltfeet - feet);		 // остаток - это дюймы
		cout << "\nctor 1\n";
	}
	// конструктор с двумя параметрами
	Distance(int ft, float in) : feet(ft), inches(in), MTF(3.280833F) { cout << "\nctor ft_in\n"; }

	// копирующий конструктор
	Distance(const Distance& of) : feet(of.feet), inches(of.inches), MTF(3.280833F) { cout << "\nctor copy\n"; }

	// получение информации от пользователя
	void getdist()
	{
		cout << "\nfeet: "; cin >> feet;
		cout << "inch: ";  cin >> inches;
	}
	// показ информации
	void showdist() const
	{
		cout << feet << "\'-" << inches << '\"';
	}
	// оператор перевода для получения метров из футов

	Distance& operator+ (const Distance&) const;
	friend Distance& operator+(const Distance&, int);
	friend Distance& operator+(int, const Distance&);

	/*explicit */ operator float() const
	{
		float fracfeet = inches / 12;	// переводим дюймы в футы
		fracfeet += static_cast<float>(feet); // добавляем целые футы
		return fracfeet / MTF;	// переводим в метры
	}

	Distance& operator= (float m)
	{
		float fltfeet = MTF * m;
		feet = int(fltfeet);
		inches = 12 * (fltfeet - feet);
		return *this;
	}

	Distance& operator=(const Distance& d)
	{
		feet = d.feet;
		inches = d.inches;
		return *this;
	}
};

Distance& Distance::operator+ (const Distance& d2) const
{
	int f = feet + d2.feet;	// складываем футы
	float i = inches + d2.inches; // складываем дюймы
	if (i >= 12.0)	// если дюймов стало больше 12
	{
		i -= 12.0;	// то уменьшаем дюймы на 12
		f++;	// и увеличиваем футы на 1
	}
	Distance temp(f, i);// создаем временную переменную
	return temp;   //   возвращаем
}

Distance& operator+(const Distance& d, int k)
{
	Distance td = k;
	return d + td;
}

Distance& operator+(int k, const Distance& d)
{
	return d + k;
}




int main()
{
	float mtrs;
	Distance dist1 = 2.35F; // используется конструктор, переводящий метры в футы и дюймы

	Distance dist101; // операция инициализации!!!
	cout << "\ndist101 = ";
	dist101.showdist();
	dist101 = 2.35F;  // операция присваивания!!! требует перегрузки оператора присваивания, так как добавлена константа и ей новое значение присваивать нельзя

	cout << "\ndist1 = ";
	dist1.showdist();

	cout << "\ndist101 = ";
	dist101.showdist();
	mtrs = static_cast<float>(dist1); // используем оператор перевода в метры
	cout << "\ndist1 = " << mtrs << " meters\n";
	Distance dist2(5, 10.25); // используем конструктор с двумя параметрами

	mtrs = dist2; // неявно используем перевод типа
	cout << "\ndist2 = " << mtrs << " meters\n";

	dist2 = mtrs;
	cout << "\ndist2 = " << " meters\n";

	Distance dist11 = dist1 + dist2;

	dist101 = dist2;
	cout << "\ndist101 = ";
	dist101.showdist();

	Distance dist102 = dist2;
	cout << "\ndist102 = ";
	dist102.showdist();

	Distance dist202 = dist2 + 22;
	cout << "\ndist202 = ";
	dist202.showdist();

	Distance dist203 = 22 + dist2;
	cout << "\ndist203 = ";
	dist203.showdist();

	Distance dist222 = dist203;
	cout << "\ndist222 = ";
	dist222.showdist();
	cout << endl;
	return 0;
}

