// #include<iostream>
// #include<vector>
// using namespace std;

// void preffix(vector<int> &v){
//     for(int i=0;i<v.size();i++){
//         v[i]+=v[i-1];
//     }
// }
// int main(){
//     int n;
//     vector<int> v;
//     cin>>n;
    
//     for(int i=0;i<n;i++){
//         int ele;
//         cin>>ele;
//         v.push_back(ele);
//     }
//     preffix(v);
//     for(int i=0;i<n;i++){
//         cout<<v[i]<<" ";
//     }
// }







#include<iostream>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;

    int arr[n];
    
    for(int i=1;i<=n;i++){
        arr[i]=i;
    }
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }

}