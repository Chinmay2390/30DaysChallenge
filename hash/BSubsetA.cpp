// there are 3 approaches 
// 1.naive approach O(m*n) O(1)
// 2.two pointer approach O(m log m + n log n) O(1)
// 3.hashset approach  O(m+n) O(m)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool subset (vector<int> a,vector<int> b){
    unordered_set<int> a_copy ;
    for(int i = 0;i<a.size();i++){
        a_copy.insert(a[i]);
    }

    for(int i = 0;i<b.size();i++){
        if(a_copy.find(b[i]) == a_copy.end()){
            return false;
        }
    }
    return true;
}
int main(){
    vector<int> a = {1,2,3,4,5};
    vector<int> b = {24,4,5};

    if(subset(a,b)){
        cout<<"TRUE"<<endl;
    }else{
        cout<<"FALSE"<<endl;
    }

    return 0;
}