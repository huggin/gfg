//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  int MaxGold(vector<vector<int>>& matrix) {
    // Code here
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(matrix);
    int ans = 0;
    for (int i = 0; i < m; ++i) {
      if (dp[0][i] == -1) dp[0][i] = -1000000000;
      ans = max(ans, dp[0][i]);
      // cout << dp[0][i] << ' ';
    }
    // cout << endl;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (matrix[i][j] != -1) {
          dp[i][j] = dp[i - 1][j] + matrix[i][j];
          if (j - 1 >= 0) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + matrix[i][j]);
          }
          if (j + 1 < m) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + matrix[i][j]);
          }
        } else {
          dp[i][j] = -1000000000;
        }
        ans = max(ans, dp[i][j]);
        // cout << dp[i][j] << ' ';
      }
      // cout << endl;
    }

    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) cin >> matrix[i][j];
    }
    Solution obj;
    int ans = obj.MaxGold(matrix);
    cout << ans << '\n';
  }
  return 0;
}
// } Driver Code Ends
