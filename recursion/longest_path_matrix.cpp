//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  vector<vector<int>> dp;
  int n, m;
  int dx[4] = {-1, 0, 0, 1};
  int dy[4] = {0, -1, 1, 0};

  int solve(int i, int j, vector<vector<int>> &mat) {
    if (dp[i][j] != -1)
      return dp[i][j];
    int &ans = dp[i][j];
    ans = 1;
    for (int k = 0; k < 4; ++k) {
      int ni = i + dx[k];
      int nj = j + dy[k];
      if (ni >= 0 && ni < n && nj >= 0 && nj < m && mat[ni][nj] > mat[i][j]) {
        ans = max(ans, solve(ni, nj, mat) + 1);
      }
    }
    return ans;
  }

public:
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    // Code here
    n = matrix.size();
    m = matrix[0].size();
    dp.assign(n, vector<int>(m, -1));

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int t = solve(i, j, matrix);
        ans = max(ans, t);
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> matrix[i][j];
    Solution obj;
    int ans = obj.longestIncreasingPath(matrix);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
