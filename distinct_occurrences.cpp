//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete this method*/

class Solution {
  vector<vector<int>> dp;
  int n, m;
  string s, t;
  const int mod = 1000000007;

  int solve(int i, int j) {
    if (i == n) return 0;
    if (j == m - 1) {
      dp[i][j] = count(s.begin() + i, s.end(), t[j]);
      // cout << i << ' ' << j << ' ' << dp[i][j] << endl;
      return dp[i][j];
    }
    if (dp[i][j] != -1) return dp[i][j];
    int& ans = dp[i][j];
    if (s[i] == t[j]) {
      ans = (solve(i + 1, j) % mod + solve(i + 1, j + 1)) % mod;
    } else {
      ans = solve(i + 1, j);
    }
    // cout << i << ' ' << j << ' ' << ans << endl;
    return ans;
  }

 public:
  int subsequenceCount(string S, string T) {
    // Your code here
    n = S.size();
    m = T.size();
    s = S, t = T;
    dp.assign(n, vector<int>(m, -1));
    return solve(0, 0);
  }
};

//{ Driver Code Starts.

//  Driver code to check above method
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    string tt;
    cin >> s;
    cin >> tt;

    Solution ob;
    cout << ob.subsequenceCount(s, tt) << endl;
  }
}
// } Driver Code Ends
