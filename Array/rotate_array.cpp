#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// int main()
// {
//     vector <int> v={0,1,2,4,5,6};
//     int k=3;
//     k=k%v.size();

//     reverse(v.begin(),v.end());
//     reverse(v.begin(),v.begin()+k);
//     reverse(v.begin()+k,v.end());
//     for(int a:v){
//         cout<<a<<" ";
//     }
// }
//     vector<int> v = {0, 1, 2, 4, 5, 6, 7};
//     int t = 3;
//     reverse(v.begin(), v.end());
//     reverse(v.begin(), v.begin() + 4);
//     reverse(v.begin() + 4, v.end());
//     for (int i : v)
//     {
//         cout << i << " ";
//     }
//     cout << endl;
//     for (int a = 0; a < v.size(); a++)
//     {
//         if (v[a] == t)
//         {
//             cout << a;
//         }
//     }
//     return -1;
// }

int main(){
    vector<int> v={0,1,2,4,5,6};
    int index;
    cout<<"Enter the index on which you want to rotate: ";
    cin>>index;
    index=index%v.size();

    reverse(v.begin(),v.end());
    reverse(v.begin(),v.begin()+index);
    reverse(v.begin()+index,v.end());
    
    cout<<endl;
    cout<<"Your rotated array is: ";
    for(int a:v){
        cout<<a<<" ";
    }
}
