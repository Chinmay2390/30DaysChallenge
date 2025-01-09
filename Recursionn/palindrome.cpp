#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

void checkPalin(string data,int s,int e){
    if(s == e){
        return;
    }
    if(data[s] != data[e]){
        cout<<"NOT PALINDROME";
        exit(0);
    }

    if(s<e){
        checkPalin(data,s+1,e-1);
    }
    
}
void palindrome(string data){

    int n = data.length();
    if(n == 1){
        cout<<"PALINDROME"<<endl;
        exit(0);
    }

    checkPalin(data,0,n-1);

}
int main(){

    string data = "geeggeog";

    palindrome(data);
    cout<<"PALINDROME"<<endl;
    return 0;
}