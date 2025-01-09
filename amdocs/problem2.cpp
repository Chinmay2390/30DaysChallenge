#include <iostream>
#include <cmath>
using namespace std;

int solve(int L, int R) {
    int count = 0;
    for (int x = L; x <= R; ++x) {
        int root = floor(sqrt(x));
        if (x % root == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int L = 12, R = 17;
    cout << "Total lucky numbers: " << solve(L, R) << endl; 
    return 0;
}