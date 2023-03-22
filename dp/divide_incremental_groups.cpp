//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  int dp[101][101][101];

  int solve(int n, int m, int k) {
    if (n == 0) {
      if (k == 0)
        return 1;
      return 0;
    }
    if (k == 0) {
      return 0;
    }
    if (dp[n][m][k] != -1)
      return dp[n][m][k];
    int &ans = dp[n][m][k];
    ans = 0;
    for (int i = m; i <= n; ++i) {
      ans += solve(n - i, i, k - 1);
    }
    return ans;
  }

public:
  int countWaystoDivide(int N, int K) {
    // Code here
    memset(dp, -1, sizeof(dp));
    return solve(N, 1, K);
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N, K;
    cin >> N >> K;
    Solution ob;
    cout << ob.countWaystoDivide(N, K) << endl;
  }
}
// } Driver Code Ends
