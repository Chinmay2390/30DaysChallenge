#include<bits/stdc++.h>
using namespace std;

int main(){
    
    //1.taking num of words
    int k;
    cin>>k;

    //2.taking words
    vector<string> val;
    for(int i = 0;i<k;i++){
        string data;
        cin>>data;
        val.push_back(data);
    }

    //3.taking lines and capacity of lines
    int n,m;
    cin>>n>>m;

    //4.sorting the data inside the vector
    sort(val.begin(), val.end(), [](const string& a, const string& b) {
        return a.size() < b.size();
    });

    for(int i = 0;i<n;i++){
        
    }
    return 0;
}