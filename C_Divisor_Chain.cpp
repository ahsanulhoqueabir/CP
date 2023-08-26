/*-----------------------------------------*
*                                          * 
*      **      ** * *    * * *   * * *     *
*     *  *     *     *     *     *    *    *
*    ******    ******      *     ** **     *
*   *      *   *     *     *     *    *    *
*  *        *  ** * *    * * *   *     *   *
___________________________________________*/

#include<bits/stdc++.h>
#define lld long long int
#define ld long double
#define py cout<<"YES"<<"\n";
#define pn cout<<"NO"<<"\n";
#define nl <<"\n";
#define srt(v) sort(v.begin(), v.end());
#define srev(str) reverse(str.begin(), str.end());
#define FOR(i,x,n) for(lld i=x;i<n;i++)

#define AHSAN ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;
// const lld N= 1e7 + 10;
// lld A[N];

void solve()
{
     int input_num; 
    cin >> input_num; 

    vector<int> result; 
    int power_of_two = 1; 

    while (power_of_two < input_num) { 
        result.push_back(power_of_two);
        power_of_two *= 2; 
    } 
    int last_element = result[result.size() - 1]; 
    int remaining = input_num - last_element; 

    bool has_one_at_end = false; 
    if (remaining % 2) { 
        has_one_at_end = true; 
        remaining--; 
    } 

    for (int i = 31; i >= 0; i--) { 
        int ith_bit = remaining & (1 << i); 
        if (ith_bit) { 
            last_element += pow(2, i); 
            result.push_back(last_element); 
        } 
    } 

    if (has_one_at_end) { 
        result.push_back(input_num); 
    } 

    int num_elements = result.size(); 
    cout << num_elements << endl; 
    for (int i = num_elements - 1; i >= 0; i--) { 
        cout << result[i] << " "; 
    } 
    cout << endl; 
}
int main()
{
    AHSAN
    int t=1;
    cin>>t;
    while (t--) solve();
}