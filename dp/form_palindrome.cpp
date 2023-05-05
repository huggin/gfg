//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  int dp[1001][1001];
  int solve(const string &s, int i, int j) {
    // if (i == j) return 1;
    if (i >= j)
      return 0;
    if (dp[i][j] != -1)
      return dp[i][j];
    if (s[i] == s[j]) {
      return dp[i][j] = solve(s, i + 1, j - 1);
    }
    dp[i][j] = min(solve(s, i + 1, j), solve(s, i, j - 1)) + 1;
    // cout << i << ' ' << j << ' ' << dp[i][j] << endl;
    return dp[i][j];
  }

public:
  int countMin(string str) {
    // complete the function here
    memset(dp, -1, sizeof(dp));
    return solve(str, 0, str.size() - 1);
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    Solution ob;
    cout << ob.countMin(str) << endl;
  }
  return 0;
}

// } Driver Code Ends
