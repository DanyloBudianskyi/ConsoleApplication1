#include "Time_ .h"

Time_::Time_()
{
	time_t t = time(0);
	tm obj;
	localtime_s(&obj, &t);
	hour = obj.tm_hour;
	minutes = obj.tm_min;
	seconds = obj.tm_sec;
	format = true;
}

Time_::Time_(int hour, int minutes, int seconds, bool format)
{
	this->hour = hour;
	this->minutes = minutes;
	this->seconds = seconds;
	this->format = format;
}

void Time_::setHour(int hour)
{
	if (hour >= 0 && hour <= MAX_HOUR)
	{
		this->hour = hour;
	}
}

int Time_::getHour() const
{
	if (format) return hour;
	else return hour - MAX_HOUR_AM_PM + 1;
}

void Time_::setMinutes(int minutes)
{
	if (minutes >= 0 && minutes <= MAX_MINUTE_SECOND)
	{
		this->minutes = minutes;
	}
}

int Time_::getMinutes() const
{
	return minutes;
}

void Time_::setSeconds(int seconds)
{
	if (seconds >= 0 && seconds <= MAX_MINUTE_SECOND)
	{
		this->seconds = seconds;
	}
}

int Time_::getSeconds() const
{
	return seconds;
}

void Time_::setFormat(bool format)
{
	this->format = format;
}

bool Time_::getFormat() const
{
	return format;
}

bool Time_::valid() const
{
	if (format)
		return (hour >= 0 && hour <= MAX_HOUR && minutes >= 0 && minutes <= MAX_MINUTE_SECOND && seconds >= 0 && seconds <= MAX_MINUTE_SECOND);
	else
		return (hour >= 0 && hour <= MAX_HOUR_AM_PM && minutes >= 0 && minutes <= MAX_MINUTE_SECOND && seconds >= 0 && seconds <= MAX_MINUTE_SECOND);
}

void Time_::tickTime()
{
	if (hour == MAX_HOUR && minutes == MAX_MINUTE_SECOND && seconds == MAX_MINUTE_SECOND)
	{
		hour = 0;
		minutes = 0;
		seconds = 0;
	}
	else if (minutes == MAX_MINUTE_SECOND && seconds == MAX_MINUTE_SECOND)
	{
		hour++;
		minutes = 0;
		seconds++;
	}
	else if (seconds == MAX_MINUTE_SECOND)
	{
		minutes++;
		seconds = 0;
	}
	else seconds++;
}

void Time_::untickTime()
{
	if (hour == 0 && minutes == 0 && seconds == 0)
	{
		hour = MAX_HOUR;
		minutes = MAX_MINUTE_SECOND;
		seconds = MAX_MINUTE_SECOND;
	}
	else if (minutes == 0 && seconds == 0)
	{
		hour--;
		minutes = MAX_MINUTE_SECOND;
		seconds = MAX_MINUTE_SECOND;
	}
	else if (seconds == 0)
	{
		minutes--;
		seconds = MAX_MINUTE_SECOND;
	}
	else seconds--;
}

void Time_::showTime() const
{
	if (format)
	{
		cout << hour / 10 << hour % 10 << ":" << minutes / 10 << minutes % 10 << ":" << seconds / 10 << seconds % 10 << endl;
	}
	else
	{
		if (hour > MAX_HOUR_AM_PM)
		{
			cout << (hour - MAX_HOUR_AM_PM - 1) / 10 << (hour - MAX_HOUR_AM_PM - 1) % 10 << ":" << minutes / 10 << minutes % 10 << ":" << seconds / 10 << seconds % 10 << " p.m" << endl;
		}
		else
		{
			cout << hour / 10 << hour % 10 << ":" << minutes / 10 << minutes % 10 << ":" << seconds / 10 << seconds % 10 << " a.m" << endl;
		}
	}
}

bool Time_::operator==(const Time_& obj) const&
{
	if (hour == obj.hour && minutes == obj.minutes && seconds == obj.seconds)
		return true;
	return false;
}

bool Time_::operator!=(const Time_& obj) const&
{
	return !(*this == obj);
}

bool Time_::operator>(const Time_& obj) const&
{
	if (this->hour > obj.hour) return true;
	else if (this->hour < obj.hour) return false;

	if (this->minutes > obj.minutes) return true;
	else if (this->minutes < obj.minutes) return false;

	if (this->seconds > obj.seconds) return true;

	return false;
}

bool Time_::operator<(const Time_& obj) const&
{
	return !(*this > obj) && (*this != obj);
}

bool Time_::operator>=(const Time_& obj) const&
{
	return (*this > obj) || (*this == obj);
}

bool Time_::operator<=(const Time_& obj) const&
{
	return (*this < obj) || (*this == obj);
}

Time_& Time_::operator+=(int s)
{
	for (int i = 0; i < s; i++)
	{
		this->tickTime();
	}
	return *this;
}

Time_& Time_::operator-=(int s)
{
	for (int i = 0; i < s; i++)
	{
		this->untickTime();
	}
	return *this;
}

Time_& Time_::operator+=(float m)
{
	minutes += (int)m;
	if (minutes > MAX_MINUTE_SECOND)
	{
		hour += minutes / (MAX_MINUTE_SECOND + 1);
		minutes = minutes % (MAX_MINUTE_SECOND + 1);
		if (hour > MAX_HOUR)
		{
			hour = hour / (MAX_HOUR + 1);
		}
	}
	return *this;
}

Time_& Time_::operator-=(float m)
{
	minutes -= (int)m;
	if (minutes < 0)
	{	
		hour -= abs(minutes) / (MAX_MINUTE_SECOND + 1) + 1;
		minutes = (MAX_MINUTE_SECOND + 1) - (abs(minutes) % (MAX_MINUTE_SECOND + 1));
		if (hour < 0)
		{
			hour = (hour + (MAX_HOUR + 1)) % (MAX_HOUR + 1);
		}
	}
	return *this;
}

Time_& Time_::operator+=(long h)
{
	hour += h % (MAX_HOUR + 1);
	if (hour > MAX_HOUR)
		hour -= MAX_HOUR + 1;
	return *this;
}

Time_& Time_::operator-=(long h)
{
	hour -= h;
	if (hour < 0)
		hour = (hour + (MAX_HOUR + 1)) % (MAX_HOUR + 1);
	return *this;
}

Time_ Time_::operator+(int s) const&
{
	Time_ tmp = *this;
	tmp += s;
	return tmp;
}

Time_ Time_::operator-(int s) const&
{
	Time_ tmp = *this;
	tmp -= s;
	return tmp;
}

Time_ Time_::operator+(float m) const&
{
	Time_ tmp = *this;
	tmp += m;
	return tmp;
}

Time_ Time_::operator-(float m) const&
{
	Time_ tmp = *this;
	tmp -= m;
	return tmp;
}

Time_ Time_::operator+(long h) const&
{
	Time_ tmp = *this;
	tmp += h;
	return tmp;
}

Time_ Time_::operator-(long h) const&
{
	Time_ tmp = *this;
	tmp -= h;
	return tmp;
}

Time_& Time_::operator--()
{
	return *this -= 1.0f;
}

Time_ Time_::operator--(int)
{
	Time_ tmp = *this;
	*this -= 1.0f;
	return tmp;
}

Time_& Time_::operator++()
{
	return *this += 1.0f;
}

Time_ Time_::operator++(int)
{
	Time_ tmp = *this;
	*this += 1.0f;
	return tmp;
}

Time_ operator+(int seconds, const Time_& a)
{
	return a + seconds;
}

Time_ operator-(int seconds, const Time_& a)
{
	return a - seconds;
}

Time_ operator+(float minutes, const Time_& a)
{
	return a + minutes;
}

Time_ operator-(float minutes, const Time_& a)
{
	return a - minutes;
}

Time_ operator+(long hours, const Time_& a)
{
	return a + hours;
}

Time_ operator-(long hours, const Time_& a)
{
	return a + hours;
}

ostream& operator<<(ostream& os, const Time_& t)
{
	if (t.format)
	{
		os << t.hour / 10 << t.hour % 10 << ":" << t.minutes / 10 << t.minutes % 10 << ":" << t.seconds / 10 << t.seconds % 10;
	}
	else
	{
		if (t.hour > t.MAX_HOUR_AM_PM)
		{
			os << (t.hour - t.MAX_HOUR_AM_PM - 1) / 10 << (t.hour - t.MAX_HOUR_AM_PM - 1) % 10 << ":" << t.minutes / 10 << t.minutes % 10 << ":" << t.seconds / 10 << t.seconds % 10 << " p.m";
		}
		else
		{
			os << t.hour / 10 << t.hour % 10 << ":" << t.minutes / 10 << t.minutes % 10 << ":" << t.seconds / 10 << t.seconds % 10 << " a.m";
		}
	}
	return os;
}

istream& operator>>(istream& is, Time_& t)
{
	do
	{
		cout << "hour minut second => ";
		is >> t.hour >> t.minutes >> t.seconds;
	} while (!t.valid());
	return is;
}