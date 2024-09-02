#include <iostream>
using namespace std;
int largest(int arr[], int n)
{
    int max = INT16_MIN;
    int maxindex=-1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            maxindex=i;
        }
    }
    return maxindex;
}

int main()
{
    int arr[7] = {1, 6, 3, 4, 5, 9, 9};
    //int arr[7] = {1, 6, 3, 4, 5, 7, 9};
    int n = 7;
    
    int first_largest=largest(arr,n);
    int large=arr[first_largest];
    cout<<"The first largest element is: ";
    cout<<arr[first_largest]<<" at index ";
    cout<<first_largest<<endl;
    //arr[first_largest]=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==large){
            arr[i]=-1;
        }
    }

     cout<<"And the Second largest element is: ";
    int second_largest=largest(arr,n);
    cout<<arr[second_largest]<<" at index "<<second_largest;

    
}