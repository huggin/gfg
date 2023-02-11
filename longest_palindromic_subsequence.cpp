//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  int dp[1001][1001];
  string s;
  int solve(int i, int j) {
    if (i > j) return 0;
    if (i == j) return 1;
    if (dp[i][j] != -1) return dp[i][j];
    if (s[i] == s[j]) return dp[i][j] = solve(i + 1, j - 1) + 2;
    return dp[i][j] = max(solve(i + 1, j), solve(i, j - 1));
  }

 public:
  int longestPalinSubseq(string A) {
    // code here
    memset(dp, -1, sizeof(dp));
    s = A;
    return solve(0, A.size() - 1);
  }
};

//{ Driver Code Starts.

int32_t main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    Solution ob;
    cout << ob.longestPalinSubseq(s) << endl;
  }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
