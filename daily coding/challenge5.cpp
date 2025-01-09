#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void leaderRoll(vector <int> arr1){
    int size = arr1.size();
    stack <int> result;
    int max = -1;
    for(int i = size-1;i>=0;i--){
        if(max<arr1[i]){
            max = arr1[i];
            result.push(arr1[i]);
            // cout<<max<<" "; 
        }
    }

    while (!result.empty()) {
        cout<< result.top()<<" ";
        result.pop();
    }

    
}
int main(){
    vector <int> arr1 = {100, 50, 20, 10};
    leaderRoll(arr1);
    return 0;
}