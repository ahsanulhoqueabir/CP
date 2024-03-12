// https://leetcode.com/problems/subsets/

/*--------------------------------------------------------*
*                                                         *
*      **       *     *   ** ****       **      *     **  *
*     *  *      *     *   *            *  *     *    ***  *
*    ******     * * * *   *** ***     ******    *   *  *  *
*   *      *    *     *         *    *      *   ***    *  *
*  *        *   *     *   *** ***   *        *  **     *  *
*_________________________________________________________*/

#include<bits/stdc++.h>
#define lld long long int
#define ld long double
#define in(x) cin >> x;
#define out(x) cout << x;
#define outs(x) cout << x <<" ";
#define outn(x) cout << x << "\n";
#define py cout<<"YES"<<"\n";
#define pn cout<<"NO"<<"\n";
#define nl cout <<"\n";
#define dsc greater<lld>()
#define srt(v) sort(v.begin(), v.end());
#define srev(str) reverse(str.begin(), str.end());
#define FOR(i,x,n) for(lld i=x;i<n;i++)
#define AHSAN ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
// const lld N= 1e7 + 10;
// lld A[N];

vector< vector<int> >allsubsets;
void generate(vector<int> &subset,int i,vector<int>&nums)
{
    if(i==nums.size())
    {
        allsubsets.push_back(subset);
        return;
    }
    generate(subset,i+1,nums);

    subset.push_back(nums[i]);
    generate(subset,i+1,nums);
    subset.pop_back();
}
void solve()
{
    
}
int main()
{
    AHSAN
    int n; in(n)
    vector<int>nums(n);
    for(int i=0;i<n;i++) in(nums[i])

    vector<int>empty;
    generate(empty,0,nums);

    for(auto subset: subsets) 
    {
        for(auto ele: subset)
        {
            outs(ele)
        } nl
    }
}