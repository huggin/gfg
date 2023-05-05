//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  int FindWays(int n, int m, vector<vector<int>> blocked_cells) {
    // Code here
    vector<vector<int>> g(n + 1, vector<int>(m + 1));
    for (auto &b : blocked_cells) {
      g[b[0]][b[1]] = 1;
    }
    if (g[1][1] == 1 || g[n][m] == 1)
      return 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    dp[1][1] = 1;
    for (int i = 2; i <= n; ++i) {
      if (g[i][1] == 1)
        dp[i][1] = 0;
      else
        dp[i][1] = dp[i - 1][1];
    }
    for (int j = 2; j <= m; ++j) {
      if (g[1][j] == 1)
        dp[1][j] = 0;
      else
        dp[1][j] = dp[1][j - 1];
    }
    for (int i = 2; i <= n; ++i) {
      for (int j = 2; j <= m; ++j) {
        if (g[i][j] == 1)
          dp[i][j] = 0;
        else
          dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
        // cout << i << ' ' << j << ' ' << dp[i][j] << endl;
      }
    }
    return dp[n][m];
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> blocked_cells;
    for (int i = 0; i < k; i++) {
      int x, y;
      cin >> x >> y;
      blocked_cells.push_back({x, y});
    }
    Solution obj;
    int ans = obj.FindWays(n, m, blocked_cells);
    cout << ans << '\n';
  }
  return 0;
}
// } Driver Code Ends
