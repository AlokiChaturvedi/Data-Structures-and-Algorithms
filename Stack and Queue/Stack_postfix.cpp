#include <iostream>
#include <math.h>
#include <stack>

using namespace std;

int calculate(int v1, int v2, char op)
{
    if (op == '^')
    {
        return pow(v1, v2);
    }
    if (op == '*')
    {
        return v1 * v2;
    }
    if (op == '/')
    {
        return v1 / v2;
    }
    if (op == '+')
    {
        return v1 + v2;
    }
    else
    {
        return v1 - v2;
    }
}

int evaluate(string &sr)
{
    stack<int> st;
    for (int i = 0; i < sr.size(); i++)
    {
        char ch = sr[i];

        if (isdigit(ch))
        {
            st.push(ch - '0');
        }
        else
        {
            int v2 = st.top();
            st.pop();
            int v1 = st.top();
            st.pop();

            st.push(calculate(v1, v2, ch));
        }
    }
    return st.top();
}

int main()
{
    string sr="231*+9-";
    cout<<evaluate(sr);
    return 0;
}