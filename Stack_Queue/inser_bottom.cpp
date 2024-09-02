#include <iostream>
#include <stack>

using namespace std;

void InsertatBottom(stack<int> &st, int x)
{
    stack<int> temp;
    while (not st.empty())
    {
        int curr = st.top();
        st.pop();
        temp.push(curr);
    }
    st.push(x);

    while (not temp.empty())
    {
        int curr = temp.top();
        temp.pop();
        st.push(curr);
    }
}

void InsertAny(stack<int> &st, int x, int idx)
{
    stack<int> temp;
    int n = st.size();
    int count = 0;
    while (count < n - idx)
    {
        count++;
        int curr = st.top();
        st.pop();
        temp.push(curr);
    }
    st.push(x);

    while (not temp.empty())
    {
        int curr = temp.top();
        temp.pop();
        st.push(curr);
    }
}

void RemoveBottom(stack<int> &st){
    stack<int> temp;
    while (st.size()!=1)
    {
        int curr = st.top();
        st.pop();
        temp.push(curr);
    }
    st.pop();

    while (not temp.empty())
    {
        int curr = temp.top();
        temp.pop();
        st.push(curr);
    }

}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(5);
    st.push(8);

    // InsertatBottom(st, 100);
    // InsertAny(st, 15, 2);
    RemoveBottom(st);
    while (not st.empty())
    {
        int curr = st.top();
        cout << curr << endl;
        st.pop();
    }

    return 0;
}