// there are 2 techiniques to find maxlength of subarray to find the sum zero
// 1.naive : we make all the subarrays and see the length which is max.
// 2.smart one : we work on the thing that Si and Sj if sum is same then we can think like to remain sum same after all the elements from i to j
// elements are minused from the Si

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxLen(vector<int> arr){
    unordered_map<int,int> sum;
    int maxlen = 0;
    int sumT = 0;

    for(int i = 0;i<arr.size();i++){
        sumT+=arr[i];

        if(sumT == 0){
            maxlen = i+1;
        }
        if(sum.find(sumT) != sum.end()){
            maxlen = max(maxlen,i-sum[sumT]);
        }else{
            sum[sumT] = i;
        }
        
    }
    return maxlen;
}
int main(){

    vector<int> arr = {1,2,4,1,5,-1,-4,-5};
    cout<<"maxlen is :"<<maxLen(arr)<<endl;

    return 0;
}