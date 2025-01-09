#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <int> arr1  = { 5,2,3,4};
    int n = arr1.size();
    int j = 1;
    for(int i=0;i<n;i++){
        if(j != arr1[i]){
            cout<<"missing element: "<<j<<endl;
            return 0;
        }
        j++;
        if(i == n-1){
            cout<<"missing element:"<<j<<endl;
            return 0;
        }
    }
    return 0;
}