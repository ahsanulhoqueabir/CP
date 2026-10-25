#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] > v[i + 1])
        {
            int curr = v[i];
            while (curr >= 10)
            {
                int d = curr % 10;
                curr /= 10;
                v.insert(v.begin() + i, d);
            }
            v.erase(v.begin() + i);
        }
        return false;
    }
    return true;
}

void B_Array_Fix()
{
    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> t;

    for (auto &x : v)
        cin >> x;

    if (is_sorted(v.begin(), v.end()))
    {
        cout << ("YES\n");
    }
    t.push_back(v.back());
    for (int i = n - 2; i >= 0; --i)
    {
        if (v[i] >= 10 && v[i] > t.back())
        {
            t.push_back(v[i] % 10);
            t.push_back(v[i] / 10);
        }
        else
        {
            t.push_back(v[i]);
        }
    }

    reverse(t.begin(), t.end());
    bool f = is_sorted(t.begin(), t.end());

    cout << (f ? "YES\n" : "NO\n");
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> v(n);
        vector<int> t;

        for (auto &x : v)
            cin >> x;

        if (is_sorted(v.begin(), v.end()))
        {
            cout << ("YES\n");
            continue;
        }
        t.push_back(v.back());
        for (int i = n - 2; i >= 0; --i)
        {
            if (v[i] >= 10 && v[i] > t.back())
            {
                t.push_back(v[i] % 10);
                t.push_back(v[i] / 10);
            }
            else
            {
                t.push_back(v[i]);
            }
        }

        reverse(t.begin(), t.end());
        bool f = is_sorted(t.begin(), t.end());

        cout << (f ? "YES\n" : "NO\n");
    }
    // B_Array_Fix();
    return 0;
}