//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  int longestCommonSubstr(string S1, string S2, int n, int m) {
    // your code here
    int ans = 0;
    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
      if (S1[i] == S2[0]) dp[i][0] = 1;
      ans = max(ans, dp[i][0]);
    }

    for (int j = 0; j < m; ++j) {
      if (S1[0] == S2[j]) dp[0][j] = 1;
      ans = max(ans, dp[0][j]);
    }

    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < m; ++j) {
        if (S1[i] != S2[j])
          dp[i][j] = 0;
        else
          dp[i][j] = dp[i - 1][j - 1] + 1;
        ans = max(ans, dp[i][j]);
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
    string s1, s2;
    cin >> s1 >> s2;
    Solution ob;

    cout << ob.longestCommonSubstr(s1, s2, n, m) << endl;
  }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
