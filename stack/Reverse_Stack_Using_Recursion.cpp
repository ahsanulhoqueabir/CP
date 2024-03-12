void reverseStack(stack<int> &s)
{
    if (s.empty())
        return;
    int x = s.top();
    s.pop();
    reverseStack(s);
    stack<int> ss;
    while (!s.empty())
    {
        ss.push(s.top());
        s.pop();
    }
    ss.push(x);
    while (!ss.empty())
    {
        s.push(ss.top());
        ss.pop();
    }
}