#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the lenght of your array: ";
    cin >> n;
    cout << endl;
    int arr[n];
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            sum = sum + arr[i];
        }
        
        else
        {
            sum = sum - arr[i];
        }
    }
    cout<<"The difference between the odd and even element is: ";
    cout << sum;
}