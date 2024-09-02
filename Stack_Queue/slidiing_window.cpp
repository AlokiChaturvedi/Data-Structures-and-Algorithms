#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int> max_window(vector<int> &arr, int k)
{
    deque<int> dq;
    vector<int> res;
    for (int i = 0; i < k ; i++)
    {
        while (not dq.empty() && arr[dq.back()] < arr[i])
        {
            dq.pop_back(i);
        }
        dq.push_back(i);
    }
    res.push_back(arr[dq.front()]);
    for (i = k; i < arr.size(); i++)
    {
        int curr = arr[i];
        if (dq.front() == (i - k))
        {
            dq.pop_front();
        }
        while (not dq.empty() && arr[dq.back()] < arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        res.push_back(arr[dq.front()]);
    }

    return res;
}

int main(){
    deque<int> dq;

    dq.push_back(10);
    dq.push_back(70);
    dq.push_back(80);
    dq.push_back(60);

    dq.push_front(6);
    dq.push_front(65);
    dq.push_front(7);

    while (not dq.empty())
    {
        cout << dq.front() << " ";
        dq.pop_front();
    }

    cout<<max_window(dq,3);

}