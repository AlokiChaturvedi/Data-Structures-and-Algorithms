#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    vector<int> v(n+1,0);
    cout << "Enter the size of your array: ";
    cin >> n;
    cout << endl
         << "Enter the elements of your array: ";
    for (int i = 1; i <= n; i++)
    {
        cin>>v[i];
    }
    cout << endl
         << "Your array is: ";
    for (int a = 1; a <=n; a++)
    {
        cout << v[a] << " ";
    }
    cout << endl;

    cout << "Enter the number of queries: ";
    int q;
    cin >> q;

    while (q--)
    {
        int p=1;
        cout<<"Your Query number "<<p<<" starts here:-"<<endl;
        int s;
        cout << "Type the starting index of sum: ";
        cin >> s;

        int e;
        cout << "Type the ending index of sum: ";
        cin >> e;
        cout << endl;

        int pre = 0;
        for (int i = s; i <= e; i++)
        {
            pre += v[i];
        }
        cout << "Your sum of elements from the index " << s << " to index " << e << " is equal to: " << pre;
        cout << endl;
        p=p+1;
    }
}