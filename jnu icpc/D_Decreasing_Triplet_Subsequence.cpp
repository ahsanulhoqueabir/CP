#include <bits/stdc++.h>
using namespace std;
// write a sive algorithom to store all prime number in range of 2 to 1e7
#define MAX 100000
vector<int> primes(MAX);
void sievePrime()
{
    bool prime[MAX] = {1};
    int p = 2;
    // while (p * p <= MAX)
    // {
    //     if (prime[p] == false)
    //     {
    //         for (int i = p * p; i <= MAX; i += p)
    //             prime[i] = true;
    //     }
    //     p++;
    // }
}
void D_Decreasing_Triplet_Subsequence()
{
    sievePrime();
    int n;
    cin >> n;
    vector<int> v(n), I, V;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int flag = 0;
        //    use upper bound or lower bound to check the x is present in primes vector
        auto itr = upper_bound(primes.begin(), primes.end(), x);
        if (*itr == x)
        {
            V.push_back(x);
        }
        // I.push_back(flag);
        // if (lower_bound(primes.begin(), itr, x)  != itr)
        // {
        //     // flag = 1;
        //     V.push_back(*lower_bound(primes.begin(), itr, x));
        // }
    }
    int size = V.size();
    for (int i = 0; i < size; i++)
    {
        cout << V[i] << " ";
    }
    for (int i = 0; i < 20; i++)
    {
        cout << primes[i] << " ";
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        D_Decreasing_Triplet_Subsequence();
    return 0;
}