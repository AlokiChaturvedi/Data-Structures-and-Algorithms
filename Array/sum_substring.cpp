#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

void substringSum(vector<int> &v){
    int total=0;
    for(int i=0;i<v.size();i++){
        total+=v[i];
    }
    
    int prefix=0;

    for(int i=0;i<v.size();i++){
        prefix+=v[i];
        int suffix=total-prefix;

        if(suffix==prefix){
            cout<<"The index where to devide the array in substring is: "<<i;
        }
}
}

int main(){
    int n;
    vector<int> v;
    cout<<"Enter the size of your array: ";
    cin>>n;
    cout<<endl<<"Enter the elements of your array: ";
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        v.push_back(ele);
    }
    substringSum(v);

}