//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  vector<vector<int>> dp;
  int n, m;

  int solve(const string& s, const string& t, int i, int j) {
    if (i >= n) {
      return 1000;
    }
    if (dp[i][j] != -1) {
      return dp[i][j];
    }
    auto st = t.find(s[i], j);
    if (st == string::npos) {
      return dp[i][j] = 1;
    }
    dp[i][j] = min(1 + solve(s, t, i + 1, st + 1), solve(s, t, i + 1, j));
    return dp[i][j];
  }

 public:
  int shortestUnSub(string S, string T) {
    // code here
    n = S.size();
    m = T.size();
    dp.assign(n, vector<int>(m + 1, -1));
    int ans = solve(S, T, 0, 0);
    return ans == 1000 ? -1 : ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    string S, T;
    cin >> S >> T;

    Solution ob;
    cout << ob.shortestUnSub(S, T) << endl;
  }
  return 0;
}
// } Driver Code Ends
