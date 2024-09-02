#include <iostream>
using namespace std;
// int count = 0;
// int most(int arr[], int n, int key)
// {
// for (int i = 0; i < n; i++)
// {
//     if (arr[i] == key)
//     {
//         count++;
//     }
//     }
//     return -1;
// };
// int main()
// {
//     int arr[] = {10, 15, 5, 1, 10};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int key = 10;
//     int mst = most(arr, n, key);
//     cout << count;
// }
int most(int *arr, int n)
{
    int maxcount=0;
    int element;
    for (int j = 0; j < n; j++)
    {
        int count=0;
        for (int i = 0; i < n; i++)
        {
            if (arr[j] == arr[i])
            {
                count++;
            }
        }
        if(count>maxcount){
            maxcount=count;
            element=arr[j];
        }

    }
    return element;
}
int main() 
{ 
    int arr[] = { 40, 50, 30, 40, 50, 30, 30 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << most(arr, n); 
    return 0; 
} 