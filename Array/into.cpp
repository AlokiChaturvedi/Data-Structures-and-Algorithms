#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the lenght of your array: ";
    cin >> n;

    int arr[n];

    cout << "Enter the element in your array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "____________________________________________" << endl;

    cout << "The element's of your array are: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
