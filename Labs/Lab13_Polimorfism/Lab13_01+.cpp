#include <iostream>
#include <string>
using namespace std;

class Item
{
public:
	Item();
	~Item();
	virtual void getData()
	{
		cout << "\nВведите заголовок: ";
		cin >> title;
		cout << "Введите цену: ";
		cin >> price;
	}

	virtual void putdata()
	{
		cout << "\nЗаголовок: " << title;
		cout << "\nЦена: " << price;
	}

private:
	string title;
	double price;
};
Item::Item()
{
}

Item::~Item()
{
}

class PaperBook : public Item
{
public:
	PaperBook();
	~PaperBook();

	void getData() override
	{
		Item::getData(); // Вызов виртуальной функции базового класса
		cout << "Введите количество страниц: ";
		cin >> pages;
	}

private:
	int pages;


};

PaperBook::PaperBook()
{
}

PaperBook::~PaperBook()
{
}

class AudioBook : public Item
{
public:
	AudioBook();
	~AudioBook();
	void getData() override
	{
		Item::getData();
		cout << "Введите время звучания : ";
		cin >> time;
	

	}

	void putdata()
	{
		Item::putdata();
		cout << "\nВремя звучания : " << time;
	}

private:
	double time;
};

AudioBook::AudioBook()
{
}

AudioBook::~AudioBook()
{
}




int main()
{
	Item* pubarr[100];

	int n = 0;
	char choice;
	do
	{
		cout << "\nВводить данные для книги или звукового файла(b / a) ? ";
		cin >> choice;
		if (choice == 'b')
			pubarr[n] = new PaperBook;
		else
			pubarr[n] = new AudioBook;
		pubarr[n++]->getData();
		cout << "Продолжать(у / n) ? ";
		cin >> choice;
	} while (choice == 'y');

	for (int j = 0; j < n; j++) {       
		pubarr[j]->putdata();       
		cout << endl;

		return 0;
	}
	
	return 0;
}