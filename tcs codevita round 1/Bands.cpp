// either give output as number or impossible...
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size:"<<endl;
    cin>>n;

    vector<vector<char>> boxIn;

    for(int i = 0;i<n;i++){
        vector<char> t;
        for(int j = 0;j<n;j++){
            char temp;
            cin>>temp;
            t.push_back(temp);
        }
        boxIn.push_back(t);
    }


    for(auto it = boxIn.begin(); it != boxIn.end();it++){
        for(auto it2 = it->begin();it2 != it->end();it2++){
             
        }
    }




    return 0;
}

// . 1 1 1 1 1 . . . . 
// . 1 . . . 1 . . . .
// . 1 . 2 2 1 2 2 . .
// . 1 . 2 . 1 . 2 . .
// . 1 1 2 1 1 . 2 . .
// . . . 2 . . . 2 . .
// . . . 2 2 2 2 2 . .
// . . . . . . . . . .
// . . . . . . . . . .
// . . . . . . . . . .