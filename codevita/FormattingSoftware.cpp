#include <bits/stdc++.h>
using namespace std;

int main() {
    // Input the number of matrices, rows, and columns
    int n, r, c, m;
    cin >> n >> r >> c;

    // Define a 3D vector to store all matrices
    vector<vector<vector<int>>> matrices(n, vector<vector<int>>(r, vector<int>(c)));

    // Input the values for each matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < c; k++) {
                cin >> matrices[i][j][k];
            }
        }
    }

    // Process matrix indices from input
    while (cin >> m) {
        m--; // Convert to zero-based index
        if (m < 0 || m >= n) {
            cout << "Invalid matrix index: " << m + 1 << "\n";
            continue;
        }

        // Print the selected matrix
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << matrices[m][i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}
