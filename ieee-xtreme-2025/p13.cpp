#include <bits/stdc++.h>
using namespace std;

void Solve()
{
    string s;
    cin >> s;
    const int n = (int)s.size();

    vector<array<int, 6>> sq;
    sq.reserve(n / 6 + 1);
    vector<int> fn;
    fn.reserve(n / 6 + 1);

    array<deque<int>, 6> wt;

    auto adv = [&](int stage, int pos) {
        int id = wt[stage].front();
        wt[stage].pop_front();
        sq[id][stage] = pos;
        if (stage == 5)
            fn.push_back(id);
        else
            wt[stage + 1].push_back(id);
    };

    for (int i = 0; i < n; ++i)
    {
        const char c = s[i];
        const int pos = i + 1;

        if (c == '1')
        {
            if (!wt[4].empty())
            {
                adv(4, pos);
            }
            else if (!wt[1].empty())
            {
                adv(1, pos);
            }
            else
            {
                sq.emplace_back();
                sq.back().fill(0);
                int id = (int)sq.size() - 1;
                sq[id][0] = pos;
                wt[1].push_back(id);
            }
        }
        else if (c == '2')
        {
            if (!wt[5].empty())
            {
                adv(5, pos);
            }
            else if (!wt[2].empty())
            {
                adv(2, pos);
            }
        }
        else if (c == '0')
        {
            if (!wt[3].empty())
            {
                adv(3, pos);
            }
        }
    }

    ostringstream out;
    for (int id : fn)
    {
        const auto &seq = sq[id];
        for (int j = 0; j < 6; ++j)
        {
            if (j)
                out << ' ';
            out << seq[j];
        }
        out << '\n';
    }

    cout << out.str();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }

    return 0;
}
