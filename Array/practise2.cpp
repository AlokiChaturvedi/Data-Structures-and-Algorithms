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