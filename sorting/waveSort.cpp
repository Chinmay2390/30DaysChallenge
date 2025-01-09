// there are 2 approaches 
// 1.naive we sort array and then swap each two adjacent elements...
// 2.If the current element is smaller than the previous odd element, swap the previous and current. 
// If the current element is smaller than the next odd element, swap next and current.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    
    vector<int> arr = {2,4,1,4,14,1,1,46,25,1345};
    for(int i = 0;i<arr.size();i+=2){
        if(i>0 && arr[i-1]>arr[i]){
            swap(arr[i-1],arr[i]);
        }
        if(i<arr.size()-1 && arr[i]<arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }

    for(auto it:arr){
        cout<<it<<" ";
    }
    return 0;
}