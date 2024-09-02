#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sortbyoddeven(vector<int> &v)
{
    int leftptr = 0;
    int rightptr = v.size() - 1;
    while (leftptr < rightptr)
    {
        if (v[leftptr] % 2 == 1 && v[rightptr] % 2 == 0)
        {
            swap(v[leftptr], v[rightptr]);
            leftptr++;
            rightptr--;
        }

        if (v[leftptr] % 2 == 0)
        {
            leftptr++;
        }

        if (v[rightptr] % 2 == 1)
        {
            rightptr--;
        }
        // while(v[leftptr]%2==0){
        //     leftptr++;
        // }
        // while(v[rightptr]%2!=0){
        //     rightptr++;
        // }
        // if(leftptr<rightptr){
        // swap(v[leftptr],v[rightptr]);}
    }
    
}
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int a = 0; a < n; a++)
    {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    sortbyoddeven(v);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}