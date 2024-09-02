#include <iostream>
using namespace std;
int main()
{
    int arr[6] = {3, 4, 0, 2, 1, 6};
    int target = 3;
    int triplet = 0;
    
    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 6; j++)
        {
            for (int k = j + 1; k < 6; k++)
            {
                if (arr[i] + arr[j] + arr[k] == target)
                {
                    triplet++;
                }
            }
        }
    }
    cout << triplet;
}