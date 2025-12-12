
#include <iostream>
using namespace std;
class A
{
	int n;
	int* arr;
public:
	A(int size) { arr = new int[size]; n = size; }
	A() : A(0) {}
	~A() { delete[] arr; }
	A(const A& other)
	{
		this->n = other.n;
		this->arr = new int[n];
		for (int i = 0; i < this->n; i++)
		{
			this->arr[i] = other.arr[i];
		}

	}

	int size() const
	{
		return n;
	}
	int& operator[](const int index) const
	{
		if (index < 0 || index > n - 1) throw out_of_range("Index out of range A object");
		return arr[index];
	}

	A& operator=(const A& other)
	{
		if (this != &other)
		{
			delete[] this->arr;
			this->n = other.n;
			this->arr = new int[n];
			for (int i = 0; i < this->n; i++)
			{
				this->arr[i] = other.arr[i];
			}
		}
		return *this;
	}

};


int main()
{

	A a1;
	A a2(10); //10 – размер массива 
	A a3 = a2;
	a1 = a3;
	a2 = A(20);
	const A a4(5);
	for (int i = 0; i < a2.size(); i++)
	{
		cout << a4[i];	

	}



	return 0;
}