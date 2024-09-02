#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sortbysquare(vector<int> &v)
{
    vector<int> aws;

    int left = 0;
    int right = v.size() -1 ;

    while (left < right)
    {
        if (abs(v[left]) < abs(v[right]))
        {
            aws.push_back(v[right] * v[right]);
            right--;
        }
        else
        {
            aws.push_back(v[left] * v[left]);
            left++;
        }
    }

    reverse(aws.begin(), aws.end());
    for (int i = 0; i < aws.size(); i++)
    {
        cout << aws[i] << " ";
    }
    
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int I = 0; I < n; I++)
    {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    sortbysquare(v);
}