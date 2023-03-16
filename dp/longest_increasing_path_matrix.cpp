//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  vector<vector<int>> dp;
  int N, M;
  vector<vector<int>> mat;
  int dx[4] = {-1, 0, 0, 1};
  int dy[4] = {0, 1, -1, 0};

  int solve(int i, int j) {
    if (dp[i][j] != -1) return dp[i][j];
    int& ans = dp[i][j];
    ans = 1;
    for (int k = 0; k < 4; ++k) {
      int ni = i + dx[k];
      int nj = j + dy[k];
      if (ni >= 0 && ni < N && nj >= 0 && nj < M && mat[i][j] < mat[ni][nj]) {
        ans = max(ans, 1 + solve(ni, nj));
      }
    }
    return ans;
  }

 public:
  int longestIncreasingPath(vector<vector<int>>& matrix, int n, int m) {
    // Code here
    dp.assign(n, vector<int>(m, -1));
    mat = matrix;
    N = n;
    M = m;
    int ans = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int t = solve(i, j);
        // cout << i << ' ' << j << ' ' << t << endl;
        ans = max(ans, t);
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> matrix[i][j];
      }
    }
    Solution obj;
    cout << obj.longestIncreasingPath(matrix, n, m) << endl;
  }
  return 0;
}

// } Driver Code Ends
