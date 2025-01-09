#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> mat = {{1,2,3,4},{43,2,41,1},{5,6,7,8},{4,2,1,5}};

    // this sortes the outer array not inner array.
    // sort(mat.begin(),mat.end());

    for(auto it:mat){
        sort(it.begin(),it.end());
        for(auto it2:it){
            cout<<it2<<" ";
        }
        cout<<endl;
    }

    return 0;
}