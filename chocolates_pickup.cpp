//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  int N, M;
  vector<vector<int>> g;
  vector<vector<vector<int>>> dp;

  int solve(int row, int l, int r) {
    if (row == N) return 0;
    if (l < 0 || r >= M) return 0;
    if (dp[row][l][r] != -1) return dp[row][l][r];
    int& ans = dp[row][l][r];
    ans = 0;
    for (int i = -1; i <= 1; ++i) {
      for (int j = -1; j <= 1; ++j) {
        int nl = l + i;
        int nr = r + j;
        if (nl > nr) swap(nl, nr);
        ans = max(ans, solve(row + 1, nl, nr));
      }
    }
    if (l == r)
      ans += g[row][l];
    else
      ans += g[row][l] + g[row][r];
    return ans;
  }

 public:
  int solve(int n, int m, vector<vector<int>>& grid) {
    // code here
    dp.assign(n, vector<vector<int>>(m, vector<int>(m, -1)));
    N = n, M = m;
    g = grid;

    return solve(0, 0, m - 1);
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid;
    for (int i = 0; i < n; i++) {
      vector<int> temp;
      for (int j = 0; j < m; j++) {
        int x;
        cin >> x;
        temp.push_back(x);
      }
      grid.push_back(temp);
    }

    Solution obj;
    cout << obj.solve(n, m, grid) << "\n";
  }
  return 0;
}
// } Driver Code Ends
