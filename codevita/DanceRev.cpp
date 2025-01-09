#include <bits/stdc++.h>
using namespace std;

bool search(int key, int fr[], int fn)
{
    for (int i = 0; i < fn; i++)
        if (fr[i] == key)
            return true;
    return false;
}

int predict(int inst[], int fr[], int pn, int fn, int index)
{
    int res = -1, farthest = index;
    for (int i = 0; i < fn; i++) {
        int j;
        for (j = index; j < pn; j++) {
            if (fr[i] == inst[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }

        if (j == pn)
            return i;
    }

    return (res == -1) ? 0 : res;
}

void optimal(int m, int inst[], int fn)
{
    int fr[fn]; // Fixed-size array for frames
    int fr_count = 0;

    int hit = 0;
    for (int i = 0; i < m; i++) {
        if (search(inst[i], fr, fr_count)) {
            hit++;
            continue;
        }

        if (fr_count < fn) {
            fr[fr_count++] = inst[i];
        } else {
            int j = predict(inst, fr, m, fn, i + 1);
            fr[j] = inst[i];
        }
    }

    cout << m - hit - 2;
}

int main()
{
    // Number of moves
    int m;
    cin >> m;

    int inst[m]; 
    string instruct;
    for (int i = 0; i < m; i++) {
        cin >> instruct;
        if (instruct == "up") {
            inst[i] = 1;
        } else if (instruct == "down") {
            inst[i] = 2;
        } else if (instruct == "right") {
            inst[i] = 3;
        } else if (instruct == "left") {
            inst[i] = 4;
        }
    }

    int fn = 2;
    optimal(m, inst, fn);
    return 0;
}
