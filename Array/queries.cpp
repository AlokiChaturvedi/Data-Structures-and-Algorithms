#include <iostream>
#include <vector>
using namespace std;
int main()
{
    cout << "Enter the size of your array: ";
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << endl;
    cout << "Your array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    
    const int N = 1e5 + 10;
    vector<int> freq(N, 0);
    for (int i = 0; i < n; i++)
    {
        freq[v[i]]++;
    }
    cout << "Enter queries: ";
    int q;
    cin >> q;
    while (q--)
    {
        int query;
        cin >> query;
        cout << freq[query] << endl;
    }
}