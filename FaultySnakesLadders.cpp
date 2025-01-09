#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, n) for (int i = (a); i < (n); ++i)
#define all(c) (c).begin(), (c).end()
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define int long long

typedef pair<int, int> pii;

struct game {
    int start;
    int end;
    string type;
};

// Function to check if the final position is reachable
bool canReachFinal(vector<int>& dieRolls, unordered_map<int, int>& board, int finalPos) {
    int position = 1;
    for (int roll : dieRolls) {
        if (position + roll <= 100) {
            position += roll;
        }
        while (board.find(position) != board.end()) {
            position = board[position];
        }
    }
    return position == finalPos;
}

void solve() {
    int N;
    cin >> N;

    vector<game> snakesLadders;
    unordered_map<int, int> board;

    // Read snakes and ladders
    loop(i, 0, N) {
        int start, end;
        cin >> start >> end;

        game sl;
        sl.start = start;
        sl.end = end;
        sl.type = (start > end) ? "Snake" : "Ladder";

        snakesLadders.push_back(sl);
        board[start] = end;
    }

    vector<int> remainingInput;
    int num;

    // Read die rolls and final position
    while (cin >> num) {
        remainingInput.push_back(num);
    }

    if (remainingInput.empty()) {
        cout << "Not reachable";
        return;
    }

    int finalPos = remainingInput.back();
    remainingInput.pop_back();
    vector<int> dieRolls = remainingInput;

    // Check if the final position is reachable without changes
    if (canReachFinal(dieRolls, board, finalPos)) {
        cout << "Not affected";
        return;
    }

    // Try to swap snakes and ladders to make it reachable
    for (int i = 0; i < snakesLadders.size(); ++i) {
        game& sl = snakesLadders[i];

        board.erase(sl.start);
        int newStart = sl.end;
        int newEnd = sl.start;
        string newType = (sl.type == "Snake") ? "Ladder" : "Snake";

        if (newStart == 1 || board.find(newStart) != board.end()) {
            board[sl.start] = sl.end;
            continue;
        }

        board[newStart] = newEnd;

        if (canReachFinal(dieRolls, board, finalPos)) {
            cout << newType << " " << newStart << " " << newEnd;
            return;
        }

        // Revert changes
        board.erase(newStart);
        board[sl.start] = sl.end;
    }

    // If no solution found
    cout << "Not reachable";
    return;
}

int32_t main() {
    fastio;
    int tc = 1;
    while (tc--) {
        solve();
    }
    return 0;
}

