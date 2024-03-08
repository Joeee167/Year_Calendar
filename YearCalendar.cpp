#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

struct stDate
{
	short Year;
	short Month;
	short Day;
};

bool IsLeap(short Year)
{
	// Checking if the year is leap or NOT

	return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}

short NumberOfDaysInMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
	{
		return 0;
	}


	// An Array that represents the number of days in each month
	short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? ((IsLeap(Year) ? 29 : 28)) : NumberOfDays[Month - 1];
}

stDate ReadDate()
{
	stDate DOB;

	cout << "\nEnter a year : ";
	cin >> DOB.Year;


	DOB.Day = 1;

	return DOB;
}

short GetDayOrder(stDate DOB)
{
	// Getting the day order in the week from "0" to "6" (Sunday to Saturday)

	short a, y, m;
	a = (14 - DOB.Month) / 12;
	y = DOB.Year - a;
	m = DOB.Month + (12 * a) - 2;
	return (DOB.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string DayInText(short DayOfWeekOrder)
{
	string arrDayNames[7] = { "Sun","Mon","Tues","Wed","Thu","Fri","Sat" };

	return arrDayNames[DayOfWeekOrder];
}

string MonthInText(short Month)
{
	string Months[12] = { "JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC" };

	return Months[Month - 1];
}

void PrintMonthCalendar(stDate DOB)
{
	// Formatting the calendar for each month

	cout << "\n\t-------------------------" << MonthInText(DOB.Month) << "-------------------------\n";

	short Days = NumberOfDaysInMonth(DOB.Month, DOB.Year);  // Get the number of days in month
	short FirstDay = GetDayOrder(DOB);  // Get the order of the first day in month

	string start = "";

	for (int i = 0; i < FirstDay; i++)
	{
		start += "\t";  // print free spaces till we reach the first day in month
	}

	for (int i = 0; i <= 6; i++)
	{
		cout << "\t" << DayInText(i);
	}

	cout << endl;
	cout << start;

	for (int j = 1; j <= Days; j++)
	{
		cout << "\t" << setw(3) << j;  //	Print each date below its day in week till saturday
		FirstDay++;

		if (FirstDay == 7)
		{
			cout << endl;  // on reaching saturday , the counter is reset to zero( Sunday) and a new line is printed
			FirstDay = 0;
		}

	}

	cout << "\n\t---------------------------------------------------\n";


}

void PrintYearCalendar(stDate Date)
{
	

	cout << "\n\t---------------------------------------------------\n";
	cout << "\t\t\tCalendar - " << Date.Year;
	cout << "\n\t---------------------------------------------------\n";

	for (int i = 1; i <= 12; i++)  // For Loop to print the calendar of each month
	{
		Date.Month = i;

		PrintMonthCalendar(Date);
	}
}

int main()
{
	
	stDate Date = ReadDate();
	

	PrintYearCalendar(Date);
	

	return 0;
}