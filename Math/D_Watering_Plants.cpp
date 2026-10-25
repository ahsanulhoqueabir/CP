#include <bits/stdc++.h>
using namespace std;
void D_Watering_Plants()
{
    int n;
    cin >> n;
    int c;
    cin >> c;
    vector<int> x;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        x.push_back(temp + (2 * c));
    }
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << " ";
    }
}
int main()
{
    D_Watering_Plants();
    return 0;
}