#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve(int N,string s,int K){
    map <char ,int> map1;

    for(char c:s){
        map1[c]++;
    }

    //sorting the map
    vector<pair<char,int>> seq(map1.begin(),map1.end());

    sort(seq.begin(), seq.end(), [](const auto &a, const auto &b) {
        return a.second < b.second; 
    });

    if(seq.size()<K){
        return -1;
    }
    if(seq.size() == K){
        return 0;
    }

    int total = 0;

    for(auto it:seq){
        total+=it.second;
        K++;
        if(K == seq.size()){
            return  total;
        }
    }

}


int main(){
    cout<<"enter details:"<<endl;
    int N;
    cin>>N;
    string s;
    cin>>s;
    int K;
    cin>>K;


    int ans = solve(N,s,K);

    cout<<"this is answer "<<ans<<endl;

    if (ans == 4) {
        cout<<"Correct..";
    }else{
        cout<<"Try again";
    }
    return 0;
}