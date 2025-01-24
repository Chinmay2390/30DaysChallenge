//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int size = arr.size();
        
        int lMax = arr[0];
        int rMax = arr[size-1];
        int left = 1;
        int right = size-2;
        int total = 0;
        
        while(left<=right){
            if(lMax<rMax){
                if(arr[left]<=lMax){
                    total+=lMax-arr[left];
                }
                if(arr[left]>lMax){
                    lMax = arr[left];
                }
                left++;
            }else{
                if(arr[right]<=rMax){
                    total+=rMax-arr[right];
                }
                if(arr[right]>rMax){
                    rMax = arr[right];
                }
                right--;
            }
            // cout<<total<<" ";
        }
        
        return total;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends