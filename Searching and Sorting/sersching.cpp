#include <iostream>
using namespace std;
int find(int arr[], int n, int key)
{
    for (int i=0; i < n; i++)
    {
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
};
int main()
{
    int arr[] = {10, 15, 5, 75, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 25;
    int posi = find(arr, n, key);
    if(posi == -1){
        cout << "The element is not present in the array!!";
    }
    else{
        cout << "The position of the elemnt in the array is : " << posi+1;
    }
    return 0;
}
 