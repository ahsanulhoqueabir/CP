#include <bits/stdc++.h>
using namespace std;
void Insert_An_Element_At_Its_Bottom_In_A_Given_Stack()
{
    int n, x;
    cin >> n >> x;
    stack<int> st, st1;
    st.push(x);
    while (n--)
    {
        int p;
        cin >> p;
        st.push(p);
    }
    while (!st.empty())
    {
        st1.push(st.top());
        st.pop();
    }
    while (!st1.empty())
    {
        cout << st1.top() << " ";
        st1.pop();
    }

    cout << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        Insert_An_Element_At_Its_Bottom_In_A_Given_Stack();
    return 0;
}

/*
Solve for Codeninja

#include <bits/stdc++.h>
stack<int> pushAtBottom(stack<int> &st1, int x)
{
    stack<int> st2;
    while (!st1.empty())
    {
        st2.push(st1.top());
        st1.pop();
    }
    st2.push(x);
    while (!st2.empty())
    {
        st1.push(st2.top());
        st2.pop();
    }
    return st1;
}
*/