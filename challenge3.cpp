#include <bits/stdc++.h>
using namespace std;

int findDuplicate(const vector<int>& arr) {

    int t = arr[0];
    int h = arr[0];
    
    do {
        t = arr[t];
        h = arr[arr[h]];
    } while (t != h);
    
    t = arr[0];

    while (t != h) {
        t = arr[t];
        h = arr[h];
    }
    
    return t; 
}

int main() {
   
    vector<int> arr1 = {1, 3, 4, 2, 2};
    cout << "Duplicate number: " << findDuplicate(arr1) << endl;
    return 0;
}
