//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  string construct(const vector<vector<int>> &dp, int i, int j) {
    if (i + 2 > j)
      return "";
    if (i + 2 == j)
      return "(**)";
    int k = dp[i][j];
    if (k == j - 1) {
      return "(" + construct(dp, i, dp[i][j]) + "*)";
    } else if (k == i + 1) {
      return "(*" + construct(dp, dp[i][j], j) + ")";
    }

    return "(" + construct(dp, i, dp[i][j]) + construct(dp, dp[i][j], j) + ")";
  }

public:
  string matrixChainOrder(int p[], int n) {
    // code here
    if (n == 2)
      return "A";
    int dp[30][30] = {0};
    vector<vector<int>> dp2(n, vector<int>(n));
    for (int k = 2; k < n; ++k) {
      dp[k - 2][k] = p[k - 2] * p[k - 1] * p[k];
    }
    for (int k = 3; k < n; ++k) {
      for (int i = 0; i + k < n; ++i) {
        dp[i][i + k] = INT_MAX;
        for (int j = i + 1; j < i + k; ++j) {
          if (dp[i][i + k] > dp[i][j] + dp[j][i + k] + p[i] * p[j] * p[i + k]) {
            dp[i][i + k] = dp[i][j] + dp[j][i + k] + p[i] * p[j] * p[i + k];
            dp2[i][i + k] = j;
          }
        }
      }
    }

    string ans = construct(dp2, 0, n - 1);
    char c = 'A';
    for (int i = 0; i < ans.size(); ++i) {
      if (ans[i] == '*') {
        ans[i] = c++;
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
    int n;
    cin >> n;
    int p[n];
    for (int i = 0; i < n; i++)
      cin >> p[i];

    Solution ob;
    cout << ob.matrixChainOrder(p, n) << "\n";
  }
  return 0;
}
// } Driver Code Ends
