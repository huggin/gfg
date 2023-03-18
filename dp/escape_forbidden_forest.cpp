//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  vector<vector<int>> dp;
  int n, m;

  int solve(const string &s, const string &t, int i, int j) {
    if (i == n || j == m)
      return 0;
    if (dp[i][j] != -1)
      return dp[i][j];
    if (s[i] == t[j])
      return dp[i][j] = 1 + solve(s, t, i + 1, j + 1);
    return dp[i][j] = max(solve(s, t, i + 1, j), solve(s, t, i, j + 1));
  }

public:
  int build_bridges(string str1, string str2) {
    // code here
    n = str1.size();
    m = str2.size();
    dp.assign(n, vector<int>(m, -1));
    return solve(str1, str2, 0, 0);
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
    string str1, str2;
    cin >> str1 >> str2;
    Solution obj;
    cout << obj.build_bridges(str1, str2) << endl;
  }
  return 0;
}

// } Driver Code Ends
