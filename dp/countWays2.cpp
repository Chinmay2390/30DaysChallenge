// Count ways to reach the nth stair using step 1 or 2

#include<iostream>
using namespace  std;

int solve(int n){
    if(n==1){
        return 1;
    }
    if(n == 2){
        return 2;
    }

    int prev1 = 1;
    int prev2 = 2;
    

    for(int i = 3;i<=n;i++){
        int curr = prev1+prev2;
        prev1 = prev2; 
        prev2 = curr;
    }

    return prev2;

}
int main(){
    int n;
    cout<<"enter the number:"<<endl;
    cin>>n;

    cout<<"counted ways to nth step:"<<solve(n);
    return 0;
}