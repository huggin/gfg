//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

// User function template for C++
class Solution {
  int n, m;
  string x, y;
  vector<vector<int>> dp;
  vector<int> hasUpper;

  int solve(int i, int j) {
    if (i == n) return 0;
    if (j == m) {
      if (i == n || hasUpper[i] == 0) {
        return 0;
      }
      return -2000;
    }
    if (dp[i][j] != -1) return dp[i][j];
    int& ans = dp[i][j];
    ans = -2000;
    if (x[i] == y[j]) {
      ans = 1 + solve(i + 1, j + 1);
    } else {
      if (x[i] >= 'a' && x[i] <= 'z') {
        ans = max(ans, solve(i + 1, j));
        if (x[i] - 'a' + 'A' == y[j]) {
          ans = max(ans, 1 + solve(i + 1, j + 1));
        }
      } else {
        ans = -2000;
      }
    }
    // cout << i << ' ' << j << ' ' << ans << endl;
    return ans;
  }

 public:
  int stringConversion(string X, string Y) {
    // Your code goes here

    n = X.size();
    m = Y.size();
    for (int i = 0; i < m; ++i) {
      if (Y[i] >= 'a' && Y[i] <= 'z') return 0;
    }
    x = X;
    y = Y;
    dp.assign(n, vector<int>(m, -1));
    hasUpper.assign(n, 0);
    for (int i = n - 1; i >= 0; --i) {
      if (X[i] >= 'A' && X[i] <= 'Z') {
        hasUpper[i] = 1;
      } else if (i < n - 1 && hasUpper[i + 1] == 1) {
        hasUpper[i] = 1;
      }
    }
    int ans = solve(0, 0);
    if (ans == m) return 1;
    return 0;
  }
};

//{ Driver Code Starts.

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    string s1, s2;
    cin >> s1 >> s2;

    Solution ob;

    cout << ob.stringConversion(s1, s2) << "\n";
  }

  return 0;
}
// } Driver Code Ends
