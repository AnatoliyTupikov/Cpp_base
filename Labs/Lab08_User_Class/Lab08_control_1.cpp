#include <iostream>

class Time
{
public:
	Time();
	Time(int hours, int minutes, int seconds);
	Time(int hours, int minutes);
	Time(int seconds);
	
	~Time();

	void set_hours(int);
	int get_hours() const { return hours; }
	void set_minutes(int);
	int get_minutes() const { return minutes; }
	void set_seconds(int);
	int get_seconds() const { return seconds; }

	void print_time();
	Time sum(Time t);

private:

	int hours;
	int minutes;
	int seconds;

};

Time::Time() : hours(0), minutes(0), seconds(0){}

Time::Time(int hours, int minutes, int seconds) 
{
	set_hours(hours);
	set_minutes(minutes);
	set_seconds(seconds);
}

Time::Time(int seconds) : Time(0, 0, seconds){}

Time::Time(int hours, int minutes) : Time(hours, minutes, 0){}


Time::~Time(){}

void Time::set_hours(int h)
{
	if (h >= 0 && h < 24)
		hours = h;
	else
		hours = 0; // default to 0 if invalid
}

void Time::set_minutes(int m)
{
	if (m < 0) {
		minutes = 0;
		return;
	}
	if (m >= 60) 
	{
		int hours = get_hours();
		hours += m / 60;
		minutes = m % 60;
		set_hours(hours); // update hours accordingly
		return;
	}
	minutes = m;
}

void Time::set_seconds(int s)
{
	if (s < 0) {
		seconds = 0;
		return;
	}
	if (s >= 60) 
	{
		int minutes = get_minutes();
		minutes += s / 60;
		seconds = s % 60;
		set_minutes(minutes); // update minutes accordingly
		return;
	}
	seconds = s;
}

void Time::print_time()
{
	std::cout << (hours < 10 ? "0" : "") << hours << ":"
		<< (minutes < 10 ? "0" : "") << minutes << ":"
		<< (seconds < 10 ? "0" : "") << seconds << std::endl;
}

Time Time::sum(const Time t) 
{
	int total_hours = get_hours() + t.get_hours();
	int total_minutes = get_minutes() + t.get_minutes();
	int total_seconds = get_seconds() + t.get_seconds();
	return Time(total_hours, total_minutes, total_seconds);
}


int main() {

	Time* t1 = new Time(10, 45, 50);
	Time* t2 = new Time(5, 30, 20);
	Time t3;
	t3 = t1->sum(*t2);
	t1->print_time();
	std::cout << "+" << std::endl;
	t2->print_time();
	std::cout << "=" << std::endl;
	t3.print_time();	

	delete t1;
	delete t2;
	return 0;
}