//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  int minInsertions(int arr[], int N) {
    // Your code goes here
    int dp[N];
    dp[0] = 1;
    int ans = 1;
    for (int i = 1; i < N; ++i) {
      dp[i] = 1;
      for (int j = 0; j < i; ++j) {
        if (arr[i] >= arr[j]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      ans = max(ans, dp[i]);
    }
    return N - ans;
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
    for (int i = 0; i < n; i++) cin >> arr[i];

    Solution ob;
    cout << ob.minInsertions(arr, n) << "\n";
  }
  return 0;
}
// } Driver Code Ends
