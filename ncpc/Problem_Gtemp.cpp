#include <bits/stdc++.h>
using namespace std;
bool isLeapYear(int year)
{
    return (year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0));
}

int daysInMonth(int month, int year)
{
    const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int result = days[month];
    if (month == 2 && isLeapYear(year))
    {
        result++;
    }
    return result;
}

int getDayOfWeek(int day, int month, int year)
{
    if (month < 3)
    {
        month += 12;
        year -= 1;
    }
    int k = year % 100;
    int j = year / 100;

    int dayOfWeek = (day + (13 * (month + 1)) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;

    return (dayOfWeek + 5) % 7; // Adjust for Sunday-based indexing
}

void printCalendar(int day, int month, int year)
{
    const vector<string> weekdays = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

    int firstDay = getDayOfWeek(1, month, year);

    cout << "|---------------------------|\n";
    cout << "|Sun|Mon|Tue|Wed|Thu|Fri|Sat|\n";
    cout << "|---------------------------|\n";

    int currentDay = 1;

    while (currentDay <= daysInMonth(month, year))
    {
        cout << "| ";
        for (int i = 0; i < weekdays.size(); ++i)
        {
            if (i < firstDay)
            {
                cout << " - ";
            }
            else
            {
                if (currentDay <= daysInMonth(month, year))
                {
                    cout << setw(2) << currentDay;
                }
                else
                {
                    cout << " - ";
                }
                currentDay++;
            }
            cout << " |";
        }
        cout << "\n|---------------------------|\n";
        firstDay = 0;
    }

    cout << "\n";
}

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t)
    {
        int day, month, year;
        char slash;

        cin >> day >> slash >> month >> slash >> year;

        cout << "\n|---------------------------|\n";
        cout << "|          ";
        cout << setw(10) << left << " " + to_string(month) + "/" + to_string(year) + "          |\n";
        cout << "|---------------------------|\n";

        printCalendar(day, month, year);
    }

    return 0;
}