#include <iostream>
using namespace std;
int main(){
    int arr[7]={1,2,1,3,4,2,3};
    int n=7;
    for(int i=0;i<7;i++){
        for(int j=i+1;j<7;j++){
            if(arr[i]==arr[j]){
                arr[i]=arr[j]=-1;
            }
        }
    }
    for(int i=0;i<7;i++){
        if(arr[i]>0){
            cout<<"Your unique element is : "<<arr[i]<<" at index: "<<i<<" of array.";
        }
    }
}