#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    vector<int> v;
    cout << "Enter the size of your array: ";
    cin >> n;
    cout << endl
         << "Enter the elements of your array: ";
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    cout << endl
         << "Your array is: ";
    for (int a = 0; a < n; a++)
    {
        cout << v[a] << " ";
    }
    cout << endl;

    cout << "Enter the number of queries: ";
    int q;
    cin >> q;

    while (q--)
    {
        int s;
        cout << "Type the starting index of sum: ";
        cin >> s;
        cout << endl;

        int e;
        cout << "Type the ending index of sum: ";
        cin >> e;
        cout << endl;

        int pre = 0;
        for (int i = s; i <= e; i++)
        {
            pre += v[i];
        }
        cout << "Your sum of elements from the index " << s << " to index " << e << " is eequal to: " << pre;
        cout << endl;
    }
}