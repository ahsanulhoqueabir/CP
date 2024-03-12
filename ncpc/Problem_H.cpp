#include <bits/stdc++.h>
using namespace std;
bool leap(string year)
{
    return (stoi(year) % 400 == 0) || ((stoi(year) % 100 != 0) && (stoi(year) % 4 == 0));
}
int getMonth(string month, string year)
{
    int x = stoi(month);
    int y = stoi(year);

    if (month == "01")
        return 31;
    else if (month == "02")
    {
        if (leap(year))
            return 29;
        else
            return 28;
    }
    else if (month == "03")
        return 31;
    else if (month == "04")
        return 30;
    else if (month == "05")
        return 31;
    else if (month == "06")
        return 30;
    else if (month == "07")
        return 31;
    else if (month == "08")
        return 31;
    else if (month == "09")
        return 30;
    else if (month == "10")
        return 31;
    else if (month == "11")
        return 10;
    else if (month == "12")
        return 31;
}
void Problem_H(int year, int month)
{
    int i, j;
    tm firstDay = {0};
    firstDay.tm_year = year - 1900;
    firstDay.tm_mon = month - 1;
    firstDay.tm_mday = 1;
    time_t tFirstDay = mktime(&firstDay);

    int firstDayOfWeek = localtime(&tFirstDay)->tm_wday;
    int n = getMonth(to_string(month), to_string(year));

    cout << "|---------------------------|\n";
    cout << "|Sun|Mon|Tue|Wed|Thu|Fri|Sat|\n";
    cout << "|---------------------------|\n";

    if (firstDayOfWeek == 0)
    {
        for (i = 1; i <= n; i++)
        {
            cout << " " << i << "|";
            if (i % 7 == 0)
            {
                cout << "\n";
                cout << "|---------------------------|\n";
            }
        }
        for (i = n + 1; i <= 35; i++)
            cout << "| - |";
        cout << "|---------------------------|\n";
    }
    else if (firstDayOfWeek == 1)
        cout << "Monday";
    else if (firstDayOfWeek == 2)
        cout << "Tuesday";
    else if (firstDayOfWeek == 3)
        cout << "Wednesday";
    else if (firstDayOfWeek == 4)
    {
        for (i = 1; i <= n; i++)
        {
            cout << " " << i << "|";
            if (i % 7 == 0)
            {
                cout << "\n";
                cout << "|---------------------------|\n";
            }
        }
        for (i = n + 1; i <= 35; i++)
            cout << "| - |";
        cout << "|---------------------------|\n";
    }
    else if (firstDayOfWeek == 5)
        cout << "Friday";
    else if (firstDayOfWeek == 6)
        cout << "Saturday";

    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;

        getline(cin, s);
        string day, month, year;

        for (int i = 0; i < 2; i++)
        {
            day += s[i];
        }
        for (int i = 3; i < 5; i++)
        {
            month += s[i];
        }
        for (int i = 6; i < 10; i++)
        {
            year += s[i];
        }

        Problem_H(stoi(year), stoi(month));
    }
    return 0;
}