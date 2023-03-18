//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  int dp[201][201];

  int solve(int n, int lo, int hi) {
    if (n == 1) return hi - lo;
    if (lo > hi) return 0;
    if (hi - lo == 1) return 1;
    if (dp[n][hi - lo] != -1) return dp[n][hi - lo];
    int& ans = dp[n][hi - lo];
    ans = hi - lo;
    for (int i = lo + 1; i <= hi; ++i) {
      ans = min(ans, max(solve(n - 1, lo, i - 1), solve(n, i, hi)) + 1);
    }
    return ans;
  }

 public:
  // Function to find minimum number of attempts needed in
  // order to find the critical floor.
  int eggDrop(int n, int k) {
    // your code here
    memset(dp, -1, sizeof(dp));
    return solve(n, 0, k);
  }
};

//{ Driver Code Starts.
int main() {
  // taking total testcases
  int t;
  cin >> t;
  while (t--) {
    // taking eggs and floors count
    int n, k;
    cin >> n >> k;
    Solution ob;
    // calling function eggDrop()
    cout << ob.eggDrop(n, k) << endl;
  }
  return 0;
}

// } Driver Code Ends
