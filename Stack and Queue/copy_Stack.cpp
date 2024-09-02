#include <iostream>
#include <stack>

using namespace std;

stack<int> copyStack(stack<int> &input)
{
    stack<int> temp;
    while (not input.empty())
    {
        int curr = input.top();
        input.pop();
        temp.push(curr);
    }

    stack<int> result;
    while (not temp.empty())
    {
        int curr = temp.top();
        temp.pop();
        result.push(curr);
    }
    return result;
}

void f(stack<int> &st, stack<int> &result){
    if(st.empty())return;
    int curr=st.top();
    st.pop();
    f(st,result);
    result.push(curr);
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(5);
    st.push(8);

    // stack<int> res = copyStack(st);
    stack<int> res;
    f(st,res);
    while (not res.empty())
    {
        int curr = res.top();
        cout << curr << endl;
        res.pop();
        
    }

    return 0;
}