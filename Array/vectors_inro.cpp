#include <iostream>
using namespace std;
#include <vector>
int main()
{
    vector<int> v;
    for (int i = 0; i < 5; i++)
    {
        int ele;
        cin >> ele;
        v.push_back(ele);
        // cin>>v[i]
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    v.pop_back();
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    v.insert(v.begin() + 2, 8);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    v.erase(v.end() - 1);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}