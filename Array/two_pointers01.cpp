#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int sortbyorder(vector<int> &v)
{
    int leftptr = 0;
    int rightptr = v.size() - 1;
    while (leftptr < rightptr)
    {
        if (v[leftptr] == 1 && v[rightptr] == 0)
        {
            v[leftptr++] = 0;
            v[rightptr--] = 1;
        }
        if (v[leftptr] == 0)
        {
            leftptr++;
        }
        if (v[rightptr] == 1)
        {
            rightptr--;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int a = 0; a < n; a++)
    {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    sortbyorder(v);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}