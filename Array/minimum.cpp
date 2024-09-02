#include <iostream>
#include <algorithm>
#include<climits>
using namespace std;
// int main()
// {
//     int arr[] = {55, 86, 26, 44, 3, 12, 98, 5};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     cout << "Array before sorting: " << endl;
//     for (int i = 0; i < n; ++i)
//         cout << arr[i] << " ";

//     sort(arr, arr + n);
//     cout << endl
//          << "Array before sorting: " << endl;
//     for (int i = 0; i < n; ++i)
//         cout << arr[i] << " ";

//     cout << endl;
//     cout << "The minimum element of the array is: " << arr[0] << endl;
//     cout << "The maximum element of the array is: " << arr[n - 1] << endl;
//     return 0;
// }
int main()
{
    int max = INT_MIN;
    int min = INT_MAX;

    int n;

    cout << "Enter the length of the array: ";
    cin >> n;
    cout << endl;

    cout << "Enter the elements of the array: "<<endl;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Your array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    cout << endl;
    cout << "The max number in the array is: " << max << endl;
    cout << "The min number in the array is: " << min << endl;
}