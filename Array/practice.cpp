#include<iostream>
using namespace std;
int main(){
    int n;
    int k;
    cout<<"Enter the no of participants : ";
    cin>>n;
    cout<<"Enter the no of passes: ";
    cin>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=i+1;
    }
    int j=0;
    for(int i=0;i<n-1;i++){
        int count=0;
        while(1){
            if(arr[j]!=-1){
                count++;
                if(count==k){
                j=j%n;
                break;
            }
            j++;
            }
            else{
            j++;
            }
            j=j%n;  
        }
        arr[j]=-1;
        while(1){
            if(arr[j%n]==-1){
                j++;
                j=j%n;
            }
            else{
                break;
            }
        }
       
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" , ";
    }cout<<endl;
    for(int i=0;i<n;i++){
        if(arr[i]!=-1){
            cout<<"The winner is : "<<arr[i]<<"th friend";
        }
    }
}