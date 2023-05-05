//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  int moves(int n, int p, int q) {
    // Your code goes here
    if (n == 1)
      return 1;
    int dp[n + 1];
    fill(dp, dp + n + 1, 10000000);
    dp[0] = 0;
    for (int i = 0; i <= n; ++i) {
      dp[i + 1] = min(dp[i + 1], dp[i] + 1);
      if (p != 1) {
        for (int j = p; i + j <= n; j *= p) {
          dp[i + j] = min(dp[i + j], dp[i] + 1);
        }
      }
      if (q != 1) {
        for (int j = q; i + j <= n; j *= q) {
          dp[i + j] = min(dp[i + j], dp[i] + 1);
        }
      }

      // cout << i << ' ' << dp[i] << endl;
    }
    return dp[n];
  }
};

//{ Driver Code Starts.

int main() {
  int n, p, q, t;
  cin >> t;
  while (t--) {
    cin >> n >> p >> q;
    Solution ob;
    cout << ob.moves(n, p, q) << endl;
  }
}

// } Driver Code Ends
