// it is similar to fibonacci but the difference is that it takes the sum of last 3 numbers..
// a[0] = a[1] = 0 and a[2] = 1
#include<iostream>
using namespace  std;

int solve(int n){
    if(n<=1){
        return 0;
    }
    if(n == 2){
        return 1;
    }
    int prev1 = 0;
    int prev2 = 0;
    int prev3 = 1;

    for(int i = 3;i<=n;i++){
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

    cout<<"tribonacci number:"<<solve(n);
    return 0;
}