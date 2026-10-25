#include <bits/stdc++.h>
using namespace std;
void A_Yes_You_can_solve_it()
{
    int n;
    cin >> n;
    set<int> x;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        x.insert(a);
    }
    if (x.size() == 1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
int main()
{
    A_Yes_You_can_solve_it();
    return 0;
}