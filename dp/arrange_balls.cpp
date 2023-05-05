//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

long long dp[101][101][101][3];

class Solution {
  const int mod = 1000000007;

  long long solve(int i, int j, int k, int p) {
    if (dp[i][j][k][p] != -1)
      return dp[i][j][k][p];

    long long &ans = dp[i][j][k][p];

    if (i == 0 && j == 0 && k == 0)
      return ans = 1;
    if (i == 0 && j == 0 && k >= 2)
      return ans = 0;
    if (i >= 2 && j == 0 && k == 0)
      return ans = 0;
    if (i == 0 && j >= 2 && k == 0)
      return ans = 0;
    ans = 0;
    if (p == 0) {
      if (j > 0) {
        ans += solve(i, j - 1, k, 1);
      }
      if (k > 0) {
        ans += solve(i, j, k - 1, 2);
      }
      ans %= mod;
    }
    if (p == 1) {
      if (i > 0) {
        ans += solve(i - 1, j, k, 0);
      }
      if (k > 0) {
        ans += solve(i, j, k - 1, 2);
      }
      ans %= mod;
    }
    if (p == 2) {
      if (j > 0) {
        ans += solve(i, j - 1, k, 1);
      }
      if (i > 0) {
        ans += solve(i - 1, j, k, 0);
      }
      ans %= mod;
    }
    return ans;
  }

public:
  int CountWays(int p, int q, int r) {
    // Code here
    memset(dp, -1, sizeof(dp));
    return ((solve(p - 1, q, r, 0) + solve(p, q - 1, r, 1)) % mod +
            solve(p, q, r - 1, 2)) %
           mod;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int p, q, r;
    cin >> p >> q >> r;
    Solution ob;
    int ans = ob.CountWays(p, q, r);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
