#include<bits/stdc++.h>
using namespace std;

int main(){
    // all locations including office
    int m;
    cin>>m;

    // take matrix to store the distance 
    int m1 [m][m];

    for(int i = 0;i<m;i++){
        for(int j = 0;j<m;j++){
            cin>>m1[i][j];
        }
    }

    // take peoples 
    int peoples[m-1];
    for(int i = 0;i<m-1;i++){
        cin>>peoples[i];
    }

    // take maximum size of bus
    int maxSize;
    cin>>maxSize;

    

    return 0;
}