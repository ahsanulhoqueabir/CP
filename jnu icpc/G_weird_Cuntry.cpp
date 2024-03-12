#include <bits/stdc++.h>
using namespace std;
vector<int> digits;
void click()
{
    bool ts(int x) {
        
        int length = log10(x)+1;
        for (int i=length-1;i>=0;--i){
            if (digits[i]!=ts_digit(x,i))
                return false;
                }
        return true;
    }
}
void G_weird_Cuntry()
{
     
}
int main()
{ 
    int t; cin >> t;
    while(t--)  G_weird_Cuntry();
    return 0;
}