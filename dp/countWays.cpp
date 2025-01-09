// Count ways to reach the nth stair using step 1, 2 or 3

#include<iostream>
using namespace  std;

int solve(int n){
    if(n==1){
        return 1;
    }
    if(n == 2){
        return 2;
    }

    if(n == 3){
        return 4;
    }
    int prev1 = 1;
    int prev2 = 2;
    int prev3 = 4;

    for(int i = 4;i<=n;i++){
        int curr = prev1+prev2+prev3;
        prev1 = prev2; 
        prev2 = prev3;
        prev3 = curr;
    }

    return prev3;

}
int main(){
    int n;
    cout<<"enter the number:"<<endl;
    cin>>n;

    cout<<"counted ways to nth step:"<<solve(n);
    return 0;
}