#include <iostream>
#include <string>
using namespace std;	

class TimeError
{
public:
	TimeError(string massage);
	~TimeError();

	string get_message() const { return message; }


private:

	string message;

};

TimeError::TimeError(string massage) : message(massage) {}

TimeError::~TimeError()
{
}

class Time
{
public:
	Time();
	Time(int hours, int minutes, int seconds);
	Time(int hours, int minutes);
	Time(int seconds);
	explicit operator int() const;

	~Time();

	void set_hours(int);
	int get_hours() const { return hours; }
	void set_minutes(int);
	int get_minutes() const { return minutes; }
	void set_seconds(int);
	int get_seconds() const { return seconds; }

	Time operator+(const Time& t) const;
	Time operator+(int secs) const;
	friend Time operator+(int secs, const Time& t);
	Time operator-(const Time& t) const;

	friend ostream& operator<< (ostream& out, const Time& t);

	bool operator< (const Time& t) const { return (int)*this < (int)t; };
	bool operator<= (const Time& t) const { return (int)*this <= (int)t; };
	bool operator> (const Time& t) const { return !(*this <= t); };
	bool operator>= (const Time& t) const { return !(*this < t); };
	bool operator== (const Time& t) const {return (int)*this == (int)t;}
	bool operator!= (const Time& t) const {return !(*this == t);}



	
	

	
	

private:

	int hours;
	int minutes;
	int seconds;

};

Time::Time() : hours(0), minutes(0), seconds(0) {}

Time::Time(int hours, int minutes, int seconds)
{
	set_hours(hours);
	set_minutes(minutes);
	set_seconds(seconds);
}

Time::Time(int seconds) : Time(0, 0, seconds) {}

Time::Time(int hours, int minutes) : Time(hours, minutes, 0) {}


Time::~Time() {}

void Time::set_hours(int h)
{
	if (h >= 0 && h < 24)
		hours = h;
	else
		throw TimeError("Hours must be between 0 and 23");
}

void Time::set_minutes(int m)
{
	if (m < 0) {
		throw TimeError("Minutes cannot be negative");
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

		throw TimeError("Seconds cannot be negative");
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

Time::operator int() const
{
	return hours * 3600 + minutes * 60 + seconds;
}

ostream& operator<< (ostream& out, const Time& t)
{
	return out << (t.hours < 10 ? "0" : "") << t.hours << ":"
				<< (t.minutes < 10 ? "0" : "") << t.minutes << ":"
				<< (t.seconds < 10 ? "0" : "") << t.seconds << std::endl;
}



Time Time::operator+(const Time& t) const
{
	int total_hours = get_hours() + t.get_hours();
	int total_minutes = get_minutes() + t.get_minutes();
	int total_seconds = get_seconds() + t.get_seconds();
	return Time(total_hours, total_minutes, total_seconds);
}

Time Time::operator+(int secs) const
{
	return *this + (Time)secs;
}



Time operator+(int secs, const Time& t)
{
	return t + secs;
}


Time Time::operator-(const Time& t) const
{
	int res = (int)*this - (int)t;
	if (res <= 0) return Time();
	return Time(res);
}




int main() {
	
	try
	{
		Time t1(1, 30, 20);
		cout << "Seconds: " << (int)t1 << endl;
		int sec = 5420;
		cout << "Time: " << (Time)sec << endl;

		cout << "Time + seconds: " << t1 + sec << endl;
		cout << "Seconds + Time: " << sec + t1 << endl;

		Time t2(10, 3, 2);
		cout << "Time1 + Time2: " << t2 + t1 << endl;
		cout << "Time2 - Time1: " << t2 - t1 << endl;

		cout << "Time2 > Time1? " << (t2 > t1) << endl;
		cout << "Time2 >= Time1? " << (t2 >= t1) << endl;
		cout << "Time2 < Time1? " << (t2 < t1) << endl;
		cout << "Time2 <= Time1? " << (t2 <= t1) << endl;
		cout << "Time2 == Time1? " << (t2 == t1) << endl;
		cout << "Time2 != Time1? " << (t2 != t1) << endl;




		
	}
	catch (TimeError& e)
	{
		std::cout << "Time Error: " << e.get_message() << std::endl;
		return 1;
	}
	
	

	return 0;
}