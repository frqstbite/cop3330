#include "date.h"

#include <cstring>
#include <iostream>
#include <string>
using namespace std;

/*
 * Private Methods
 */

int Date::getDaysInMonth() const {
	switch (month) {
		// The weird month
		case 2:
			return 28 + (isLeapYear() ? 1 : 0);

		// Long months
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;

		// Short months
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
	}
}

bool Date::isLeapYear() const {
	return (year % 100 == 0) ? (year % 400 == 0) : (year % 4 == 0);
}

bool Date::isValid() const {
	// Year
	if (year < 1900)
		return false;

	// Month
	if (month < 1 || month > 12)
		return false;

	// Day
	if (day < 1 || day > getDaysInMonth())
		return false;

	return true; // Valid
}

int Date::sakamoto(int m, int d, int y) const {
	static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
	y -= m < 3;
	return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}

/*
 * Constructors
 */

// Default
Date::Date() : Date(1, 1, 2025) {}

// Parametered
Date::Date(int m, int d, int y) : month(m), day(d), year(y) {
	// Invalid dates are reset
	if (!isValid())
		Set(1, 1, 2025);
}

// Cast
Date::Date(const char *str) {
	string obj = str;

	// Find positions of the slashes
	int firstSlash = obj.find('/');
	int secondSlash = obj.find('/', firstSlash + 1);

	// Extract substrings and convert to int
	month = stoi(obj.substr(0, firstSlash));
	day = stoi(obj.substr(firstSlash + 1, secondSlash - firstSlash - 1));
	year = stoi(obj.substr(secondSlash + 1));

	// Invalid dates are reset
	if (!isValid())
		Set(1, 1, 2025);
}

/*
 * Methods
 */

void Date::Input() {
	cout << "Input date in month/day/year format: ";
	cin >> month;
	cin.ignore(1, '/');
	cin >> day;
	cin.ignore(1, '/');
	cin >> year;

	// Validate input if necessary
	while (!isValid()) {
		cout << "Invalid date. Try again: ";
		cin >> month;
		cin.ignore(1, '/');
		cin >> day;
		cin.ignore(1, '/');
		cin >> year;
	}
}

int Date::GetMonth() const { return month; }

int Date::GetDay() const { return day; }

int Date::GetYear() const { return year; }

bool Date::Set(int m, int d, int y) {
	int currentMonth = month = m;
	int currentDay = day = d;
	int currentYear = year = y;

	if (!isValid()) {
		month = currentMonth;
		day = currentDay;
		year = currentYear;
		return false;
	}

	return true;
}

void Date::Increment() {
	if (day == getDaysInMonth()) {
		if (month == 12) {
			year++;
			month = 1;
		} else
			month++;

		day = 1;
	} else
		day++;
}

void Date::Decrement() {
	if (day == 1) {
		if (month == 1) {
			if (year == 1900)
				return; // Lower limit
			else
				year--;

			month = 12;
		} else
			month--;

		day = getDaysInMonth();
	} else
		day--;
}

int Date::DayofWeek() const {
	// Use Sakamoto’s Algorithm
	return sakamoto(month, day, year);
}

int Date::Compare(const Date &d) const {
	// Years
	if (year < d.year)
		return -1;
	if (year > d.year)
		return 1;

	// Months
	if (month < d.month)
		return -1;
	if (month > d.month)
		return 1;

	// Days
	if (day < d.day)
		return -1;
	if (day > d.day)
		return 1;

	// Everything is equal
	return 0;
}

void Date::ShowByDay() const {
	switch (DayofWeek()) {
		case 0:
			cout << "Sunday";
			break;
		case 1:
			cout << "Monday";
			break;
		case 2:
			cout << "Tuesday";
			break;
		case 3:
			cout << "Wednesday";
			break;
		case 4:
			cout << "Thursday";
			break;
		case 5:
			cout << "Friday";
			break;
		case 6:
			cout << "Saturday";
			break;
	}

	cout << ' ' << month << '/' << day << '/' << year << endl;
}

void Date::ShowByMonth() const {
	const char *sep = "    ";

	// Month    Year
	switch (month) {
		case 1:
			cout << "January";
			break;
		case 2:
			cout << "February";
			break;
		case 3:
			cout << "March";
			break;
		case 4:
			cout << "April";
			break;
		case 5:
			cout << "May";
			break;
		case 6:
			cout << "June";
			break;
		case 7:
			cout << "July";
			break;
		case 8:
			cout << "August";
			break;
		case 9:
			cout << "September";
			break;
		case 10:
			cout << "October";
			break;
		case 11:
			cout << "November";
			break;
		case 12:
			cout << "December";
			break;
	}
	cout << sep << year << endl;

	// Week header
	cout << "Su" << sep << "Mo" << sep << "Tu" << sep << "We" << sep << "Th"
		 << sep << "Fr" << sep << "Sa" << endl;

	int daysInMonth = getDaysInMonth();
	int firstDay = sakamoto(month, 1, year);

	// d is 1-daysInMonth, inclusive; negative values are empty spaces
	// wd is 0-6, inclusive
	for (int d = 1 - firstDay, wd = 0; d <= daysInMonth;
		 d++, wd = (wd + 1) % 7) {

		if (d < 1)
			cout << "  "; // Negative days render empty
		else {
			if (d < 10)
				cout << '0'; // Extra 0 for single-digit numbers
			cout << d;
		}

		// For all days except the last...
		if (d < daysInMonth)
			if (wd == 6)
				// Wrap line
				cout << endl;
			else
				// Or pad out for next day
				cout << sep;
	}

	cout << endl; // For good measure c:
}
