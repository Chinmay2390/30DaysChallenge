#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1,2,3,56,5};
    for(int i = 1;i<arr.size();i++){
        if(arr[i-1]<=arr[i]){
            continue;
        }else{
            cout<<"unsorted"<<endl;
            exit(0);
        }
    }
    cout<<"sorted"<<endl;
    return 0;
}