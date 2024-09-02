#include <iostream>
using namespace std;
int binary(int arr[], int n, int key)
{
    int s = 0;
    int e = n;
    while (s <= e)
    {
        int mid = (s + e)/ 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
};
int main()
{
    int n;
    cout << "Enter the lenght of your array: ";
    cin >> n;
    cout << endl
         << "Enter the elements of the array: ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<"Your Array is: " ;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<<" ";
    }
    cout <<endl;
    int key;
    cout << "Enter the element to search: ";
    cin >> key;
    int posi = binary(arr, n, key);
    if(posi == -1){
        cout << "The element is not present in the array!!";
    }
    else{
        cout << "The position of the elemnt in the array is : " << posi;
    }
    return 0;
}