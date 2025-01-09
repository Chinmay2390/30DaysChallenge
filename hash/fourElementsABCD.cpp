// the task is to find the four elements a,b,c,d such as a+b = c+d
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void sum_match(vector<int> arr){
    // we create a hash_map
    unordered_map<int,pair<int,int>> sum;
    for(int i = 0;i<arr.size();i++){
        for(int j = i+1;j<arr.size();j++){
            int sumT = arr[i]+arr[j];
            if(sum.find(sumT) == sum.end()){
                sum[sumT] = make_pair(i,j);
            }else{
                //pair is found
                pair<int,int> pp = sum[sumT];
                cout<<arr[i]<<" "<<arr[j]<<" "<<arr[pp.first]<<" "<<arr[pp.second]<<endl;
                return;
            }
        }
    }

    cout<<"NO PAIR FOUND"<<endl;
}
int main(){

    vector<int> arr = {11,0,2,1,15,6,4,451,5676,41,3};
    
    sum_match(arr);
    return 0;
}