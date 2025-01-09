// there are 2 ways to solve this problem 
// 1.naive approach O(n*k) O(1)
// 2.sliding window approach O(n) O(k)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


vector<int> countUnique(vector<int> arr,int k){
    vector<int> res;
    unordered_map<int,int> freqCount;
    for(int i = 0;i<k;i++){
        freqCount[arr[i]] += 1;
    }
    res.push_back(freqCount.size());

    // window updating 
    for(int i = k ;i<arr.size();i++){
        freqCount[arr[i]] += 1;
        freqCount[arr[i-k]] -= 1;

        if(freqCount[arr[i-k]] == 0){
            freqCount.erase(i-k);
        }
        res.push_back(freqCount.size());
    }

    return res;
}


int main(){
    // vector<int> arr = {1,4,1,15,6,2,26,1567,14567,5,124,1457};
    vector<int> arr = {1, 2, 1, 3, 4, 2, 3};
    int k = 4;
    vector<int> res = countUnique(arr,k);

    for(int i:res){
        cout<<i<<" ";
    }

    return 0;
}