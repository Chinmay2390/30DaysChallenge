// there is another technique beside the give below tech that we can use the hash array which will 
// store the count of each character inside the string and then at last using loop will print those 
// characters...

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string data = "geeksforgeeks";
    vector<char> data1 = {'a','b','c','a'};
    vector<int> data2 = {1,3,2,1,1};

    sort(data2.begin(),data2.end());
    sort(data.begin(),data.end());
    sort(data1.begin(),data1.end());

    for(auto it = data.begin();it!=data.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    for(auto it = data1.begin();it!=data1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    for(auto it = data2.begin();it!=data2.end();it++){
        cout<<*it<<" ";
    }

    return 0;
}