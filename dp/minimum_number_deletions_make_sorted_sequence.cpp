//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  int minDeletions(int arr[], int n) {
    // Your code goes here
    vector<int> dp;
    for (int i = 0; i < n; ++i) {
      if (dp.empty()) {
        dp.push_back(arr[i]);
      } else {
        auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
        if (it == dp.end()) {
          dp.push_back(arr[i]);
        } else {
          *it = arr[i];
        }
      }
    }
    return n - dp.size();
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
      cin >> arr[i];

    Solution ob;
    cout << ob.minDeletions(arr, n) << "\n";
  }
  return 0;
}
// } Driver Code Ends
