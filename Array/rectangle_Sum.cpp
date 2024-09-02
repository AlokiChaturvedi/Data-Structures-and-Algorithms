#include<iostream>
#include<vector>
using namespace std;

int rectangleSum(vector < vector<int>> &vec, int l1, int l2,int r1,int r2){
int sum=0;
for(int i=l1;i<=l2;i++){
    for(int j=r1;j<=r2;j++){
        sum+=vec[i][j];
    }
}
return sum;
}

 int main(){
    int n,m;
    cout<<"Enter the value of row and column: ";
    cin>>n>>m;
    vector<vector<int>> vec(n,vector<int>(m));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>vec[i][j];
        }
    }

    cout<<endl<<"Your matrix is: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<vec[i][j]<<" ";
        }cout<<endl;
    }
    cout<<"Enter the co-ordinates of rectangle: ";
    int l1,l2,r1,r2;
    cin>>l1>>r1>>l2>>r2;

    int sum= rectangleSum(vec,l1,l2,r1,r2);
    cout<<"The sum of the the rectangle formed is : "<<sum;
     return 0;
 }