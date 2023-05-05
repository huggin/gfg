//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  vector<vector<int>> dp;
  int n, m;
  int cx, cy;
  string x, y;

  int solve(int i, int j) {
    if (i == n)
      return (m - j) * cy;
    if (j == m)
      return (n - i) * cx;
    if (dp[i][j] != -1)
      return dp[i][j];
    if (x[i] == y[j]) {
      // cout << i << ' ' << j << ' ' << solve(i+1, j+1) << endl;
      return dp[i][j] = solve(i + 1, j + 1);
    }
    dp[i][j] = min(solve(i + 1, j) + cx, solve(i, j + 1) + cy);

    // cout << i << ' ' << j << ' ' << dp[i][j] << endl;
    return dp[i][j];
  }

public:
  int findMinCost(string X, string Y, int costX, int costY) {
    // Your code goes here
    n = X.size();
    m = Y.size();
    dp.assign(n, vector<int>(m, -1));
    cx = costX;
    cy = costY;
    x = X;
    y = Y;
    return solve(0, 0);
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    string x, y;
    cin >> x >> y;

    int costX, costY;
    cin >> costX >> costY;

    Solution ob;
    cout << ob.findMinCost(x, y, costX, costY);
    cout << "\n";
  }
  return 0;
}

// } Driver Code Ends
