//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  vector<int> FindWays(vector<vector<int>>& matrix) {
    // Code here
    const int M = 1e9 + 7;
    int n = matrix.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2)));

    dp[0][0] = {1, matrix[0][0]};
    for (int i = 1; i < n; ++i) {
      if ((matrix[i - 1][0] == 2 || matrix[i - 1][0] == 3) &&
          dp[i - 1][0][0] != 0)
        dp[i][0] = {1, dp[i - 1][0][1] + matrix[i][0]};

      if ((matrix[0][i - 1] == 1 || matrix[0][i - 1] == 3) &&
          dp[0][i - 1][0] != 0)
        dp[0][i] = {1, dp[0][i - 1][1] + matrix[0][i]};
    }

    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < n; ++j) {
        if ((matrix[i - 1][j] == 2 || matrix[i - 1][j] == 3) &&
            dp[i - 1][j][0] != 0) {
          dp[i][j][0] += dp[i - 1][j][0];
          dp[i][j][0] %= M;
          dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][1] + matrix[i][j]);
        }
        if ((matrix[i][j - 1] == 1 || matrix[i][j - 1] == 3) &&
            dp[i][j - 1][0] != 0) {
          dp[i][j][0] += dp[i][j - 1][0];
          dp[i][j][0] %= M;
          dp[i][j][1] = max(dp[i][j][1], dp[i][j - 1][1] + matrix[i][j]);
        }
      }
    }

    return dp[n - 1][n - 1];
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) cin >> matrix[i][j];
    }
    Solution obj;
    vector<int> ans = obj.FindWays(matrix);
    for (auto i : ans) cout << i << " ";
    cout << "\n";
  }
  return 0;
}
// } Driver Code Ends
