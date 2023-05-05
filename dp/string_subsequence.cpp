//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  int dp[501][501];
  string s1, s2;
  int n, m;

  int solve(int i, int j) {
    if (j == m)
      return 1;
    if (i == n)
      return 0;
    if (dp[i][j] != -1)
      return dp[i][j];
    int &ans = dp[i][j];

    ans = solve(i + 1, j);
    if (s1[i] == s2[j]) {
      ans += solve(i + 1, j + 1);
    }
    return ans;
  }

public:
  int countWays(string S1, string S2) {
    // code here
    memset(dp, -1, sizeof(dp));
    s1 = S1;
    s2 = S2;
    n = s1.size();
    m = s2.size();
    return solve(0, 0);
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    string S1, S2;
    cin >> S1;
    cin >> S2;

    Solution ob;
    cout << ob.countWays(S1, S2) << endl;
  }
  return 0;
}
// } Driver Code Ends
