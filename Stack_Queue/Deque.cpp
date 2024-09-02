#include<iostream>
#include<deque>

using namespace std;

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


    return 0;
}