//program to find nth find fibonacci number
#include<iostream>
using namespace std;
int solve(int n){
    if(n<=1){
        return n;
    }
    int prev1 = 1;
    int prev2 = 0;

    for(int i = 2;i<=n;i++){
        int curr = prev1+prev2;
        prev2 = prev1; 
        prev1 = curr;
    }

    return prev1;

}
int main(){
    int n;
    cout<<"enter the number:"<<endl;
    cin>>n;

    cout<<"fibonacci number:"<<solve(n);
    return 0;
}

