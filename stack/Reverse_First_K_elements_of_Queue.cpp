#include <bits/stdc++.h>
queue<int> reverseElements(queue<int> q, int k)
{
    // Write your code here.
    stack<int> s;
    while (k--)
    {
        s.push(q.front());
        q.pop();
    }
    queue<int> qq;
    while (!s.empty())
    {
        qq.push(s.top());
        s.pop();
    }
    while (!q.empty())
    {
        qq.push(q.front());
        q.pop();
    }
    return qq;
}

int main()
{
}