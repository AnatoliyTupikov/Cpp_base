#include <iostream>
using namespace std;

class Stack
{
public:
	int data[10]{};
	int size = 0;
	void reset() {
		for (int i = 0; i < size; i++) {
			data[i] = 0;
		}
		size = 0;
	}

	bool push(int value) {
		if (size >= 10) {
			return false;
		}
		data[size] = value;
		size++;
		return true;
	}

	int pop()
	{
		if (size == 0) { cout << "The stack is empty!" << endl; return 0; }
		int res = data[--size];
		data[size] = 0;
		return res;
		
	}

	void print()
	{
		cout << "(";
		for (int i = 0; i < size; i++) {
			cout << " " << data[i];
		}
		cout << " )" << endl;
	}

};


int main()
{
	Stack stack;
	stack.reset();
	stack.print();
	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();
	stack.pop();
	stack.print();
	stack.pop();
	stack.pop();
	stack.print();





	return 0;
}