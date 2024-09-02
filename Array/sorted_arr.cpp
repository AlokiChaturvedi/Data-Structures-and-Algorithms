#include <iostream>
using namespace std;
int main()
{
    int arr[5]={1,4,2,3,7};
    bool flag=true;
    for (int i = 1; i < 5; i++)
    {
        if (arr[i] <= arr[i - 1])
        {
            flag = false;
        }
    }
    cout << flag;
}