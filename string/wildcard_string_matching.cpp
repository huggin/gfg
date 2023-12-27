//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution {
  char dp[1001][1001];
  string W;
  string P;

  int solve(int i, int j) {
    if (i == W.size() && j == P.size())
      return 1;
    if (i == W.size()) {
      if (j != P.size())
        return 0;
    } else {
      if (j == P.size()) {
        while (i < W.size()) {
          if (W[i++] != '*')
            return 0;
        }
        return 1;
      }
    }
    if (dp[i][j] != -1)
      return dp[i][j];
    if (W[i] == P[j])
      return dp[i][j] = solve(i + 1, j + 1);
    if (W[i] == '?')
      return dp[i][j] = solve(i + 1, j + 1);
    if (W[i] == '*') {
      return dp[i][j] =
                 solve(i, j + 1) || solve(i + 1, j + 1) || solve(i + 1, j);
    }
    return dp[i][j] = 0;
  }

public:
  bool match(string wild, string pattern) {
    // code here
    memset(dp, -1, sizeof(dp));
    W = wild;
    P = pattern;
    return solve(0, 0);
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    string wild, pattern;
    cin >> wild >> pattern;

    Solution ob;
    if (ob.match(wild, pattern))
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
// } Driver Code Ends
