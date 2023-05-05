//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  long long dp[5][10001];
  int n;
  string s;
  string p = "GEEKS";
  int mod = 1000000007;

  long long solve(int i, int j) {
    if (j == 5)
      return 1;
    if (i == n)
      return 0;
    if (dp[j][i] != -1)
      return dp[j][i];
    long long &ans = dp[j][i];
    ans = solve(i + 1, j);
    ans %= mod;
    if (s[i] == p[j]) {
      ans += solve(i + 1, j + 1);
      ans %= mod;
    }
    return ans;
  }

public:
  int TotalWays(string str) {
    // Code here
    memset(dp, -1, sizeof(dp));
    n = str.size();
    s = str;
    return solve(0, 0);
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    string str;
    cin >> str;
    Solution ob;
    int ans = ob.TotalWays(str);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
