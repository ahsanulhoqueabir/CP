#include <bits/stdc++.h>
int Sum(stack<int> s)
{
    int sum = 0;
    while (!s.empty())
    {
        sum += s.top();
        s.pop();
    }
    return sum;
}
int maxSum(stack<int> &stk1, stack<int> &stk2, stack<int> &stk3)
{
    int sum1 = Sum(stk1), sum2 = Sum(stk2), sum3 = Sum(stk3);
    while (true)
    {
        if (sum1 == sum2 and sum2 == sum3)
        {
            break;
        }
        if (sum1 >= sum3 and sum1 >= sum2)
        {
            sum1 -= stk1.top();
            stk1.pop();
        }
        else if (sum2 >= sum3 and sum2 >= sum1)
        {
            sum2 -= stk2.top();
            stk2.pop();
        }
        else
        {
            sum3 -= stk3.top();
            stk3.pop();
        }
    }
    return sum1;
}

// it will give err there. its for codeninja