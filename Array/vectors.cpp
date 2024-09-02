#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v={1,3,5,7};

    vector <int> c={2,4,6,8};

    vector<int> ans;
    int i=0;
    int k=0;

    while(i<4 && k<4){
        if(v[i]<c[k]){
            ans.push_back(v[i]);
            i++;
        }
        else{
            ans.push_back(c[k]);
            k++;
        }
    }
    while(i<4){
        ans.push_back(v[i]);
            i++;
    }
    while(k<4){
        ans.push_back(c[k]);
            k++;
    }
    for(int e:ans){
        cout<<e;
    }
        
    }
