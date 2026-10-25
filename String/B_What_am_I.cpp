#include <bits/stdc++.h>
using namespace std;
void B_What_am_I()
{
    char ch;
    cin >> ch;
    if (ch >= 'A' && ch <= 'Z')
        cout << "A";
    else if (ch >= 'a' && ch <= 'z')
        cout << "a";
}
int main()
{
    B_What_am_I();
    return 0;
}