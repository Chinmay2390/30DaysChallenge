//Minimum cost to reach the top of the floor by climbing stairs

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> &steps){
    
}

int main(){
    int n;
    cout<<"Enter the number of stairs:"<<endl;
    cin>>n;
    vector<int> steps;
    cout<<"Enter the cost of stairs:"<<endl;
    for(int i = 0;i<n;i++){
        int temp;
        cin>>temp;
        steps.push_back(temp);
    }

    cout<<"minimum cost:"<<solve(steps);
    return 0;
}