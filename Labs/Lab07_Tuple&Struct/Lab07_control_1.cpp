#include <iostream> 
#include <windows.h> 
#include <string> 
#include <tuple> // connect tuple
#include <vector> 
using namespace std;

struct Time 
{
	int hours;
	int minutes;
	int seconds;

	void displayTime() 
	{
		cout << hours << " : " << minutes << " : " << seconds << endl;
	}

	void displayTotalSeconds() 
	{
		
		cout << "Total seconds: " << getTotalSeconds() << endl;
	}

	void addTime(const Time& t) 
	{
		seconds += t.seconds;
		minutes += t.minutes + seconds / 60;
		hours += t.hours + minutes / 60;
		seconds %= 60;
		minutes %= 60;
	}

	void subtractTime(const Time& t)
	{		
		int totalSeconds1 = this->getTotalSeconds();
		int totalSeconds2 = t.getTotalSeconds();
		if (totalSeconds1 < totalSeconds2) 
		{
			hours = 0;
			minutes = 0;
			seconds = 0;
			return;
		}
		int diffSeconds = abs(totalSeconds1 - totalSeconds2);
		hours = diffSeconds / 3600;
		minutes = (diffSeconds % 3600) / 60;
		seconds = diffSeconds % 60;
	}

private:
	int getTotalSeconds() const 
	{
		return hours * 3600 + minutes * 60 + seconds;
	}
};


int main()
{

	

	int h, m, s;
	cout << "Specify time: " << endl;
	cout << "\tHours: ";
	cin >> h;
	cout << "\tMinutes: ";
	cin >> m;
	cout << "\tSeconds: ";
	cin >> s;
	Time time1 = { h, m, s };
	cout << "Time: ";
	time1.displayTime();
	time1.displayTotalSeconds();

	Time timeA = { 2, 30, 15 };
	cout << "Time A: ";
	timeA.displayTime();
	timeA.displayTotalSeconds();

	cout << "Adding Time A to Time 1..." << endl;
	time1.addTime(timeA);
	cout << "New Time 1: ";
	time1.displayTime();
	cout << "Subtracting Time A from Time 1..." << endl;
	time1.subtractTime(timeA);
	cout << "New Time 1: ";
	time1.displayTime();




	return 0;
}