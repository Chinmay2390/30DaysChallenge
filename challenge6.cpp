#include <bits/stdc++.h>


using namespace std;

vector<pair<int, int>> findZeroSumSubarrays(const vector<int>& arr) {
    vector<pair<int, int>> result;
    unordered_map<int, vector<int>> sumIndexMap;
    int cumulativeSum = 0;

    for (int i = 0; i < arr.size(); i++) {
        cumulativeSum += arr[i];
        
        // If cumulative sum is zero, add subarray from index 0 to i
        if (cumulativeSum == 0) {
            result.push_back({0, i});
        }
        
        // If cumulative sum has been seen before, all subarrays between previous indices and i sum to zero
        if (sumIndexMap.find(cumulativeSum) != sumIndexMap.end()) {
            for (int startIdx : sumIndexMap[cumulativeSum]) {
                result.push_back({startIdx + 1, i});
            }
        }
        
        // Store the index for this cumulative sum
        sumIndexMap[cumulativeSum].push_back(i);
    }

    return result;
}

int main() {
    vector<int> arr = {0,0,0};

    vector<pair<int, int>> result = findZeroSumSubarrays(arr);
    
    // Print the result
    for (auto it : result) {
        cout << "(" << it.first << ", " << it.second << ")" << endl;
    }

    return 0;
}
