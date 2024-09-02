#include <iostream>
#include<cmath>
using namespace std;


// int main(){
//     int n;
//     cin>>n;

//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=(n-i);j++){
//             cout<<"  ";
//         }
//         for(int k=i;k>0;k--){
//             cout<<k<<" ";
//         }
//         for(int l=2;l<=i;l++){
//             cout<<l<<" ";
//         }
//         cout<<endl;
//     }
// }

// int main()

// {
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j <(n - i - 1); j++)
//         {
//             cout << "  ";
//         }
//         for (int k = 0; k < (2 * i) + 1; k++)
//         {
//             cout << "* ";
//         }

//         cout << endl;
//     }
//     for (int i = n; i > 0; i--)
//     {
//        for (int j = 0; j <= (n - i - 1); j++)
//         {
//             cout << "  ";
//         }
//         for (int k = 0; k < (2 * i) -1; k++)
//         {
//             cout << "* ";
//         }

//         cout << endl;
//     }
// }

int f(int n){
    if(n>1){
    return n*f(n-1);
    }
    else {
        return 1;
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<f(i)/(f(j)*f(i-j))<<" ";
        }
        cout<<endl;
    }
}