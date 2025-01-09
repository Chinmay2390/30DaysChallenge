// two sum problem can be done by lot of methods like 
// 1.hash set (but this solution is expected...)
// 2.two pointer search
// 3.binary search 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool twoSum(int arr[],int target,int size){
    unordered_set<int> str;
    for(int i = 0;i<size;i++){
        int complement = target-arr[i];
        if(str.find(complement) != str.end()){
            return true;
        }
        str.insert(arr[i]);

    }
    return false;
}
int main(){

    int arr[] = {1,2,1,52,14,1};
    int target = 2;
    int size = sizeof(arr) / sizeof(arr[0]);
    if(twoSum(arr,target,size)){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    return 0;
}