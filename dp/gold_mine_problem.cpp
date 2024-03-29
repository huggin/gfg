//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  int dp[50][50];

public:
  int maxGold(int n, int m, vector<vector<int>> M) {
    // code here
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) {
      dp[i][0] = M[i][0];
    }
    for (int j = 1; j < m; ++j) {
      for (int i = 0; i < n; ++i) {
        dp[i][j] = dp[i][j - 1];
        if (i >= 1) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
        }
        if (i < n - 1) {
          dp[i][j] = max(dp[i][j], dp[i + 1][j - 1]);
        }
        dp[i][j] += M[i][j];
      }
    }
    int ans = INT_MIN;
    for (int i = 0; i < n; ++i) {
      ans = max(ans, dp[i][m - 1]);
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
    vector<vector<int>> M(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        cin >> M[i][j];
    }

    Solution ob;
    cout << ob.maxGold(n, m, M) << "\n";
  }
  return 0;
}
// } Driver Code Ends
