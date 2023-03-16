//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  vector<vector<int>> dp;
  int n, m;
  string S, T;
  string temp;
  set<string> us;

  int solve(int i, int j) {
    if (i == n || j == m) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int& ans = dp[i][j];
    if (S[i] == T[j]) {
      ans = 1 + solve(i + 1, j + 1);
    } else {
      ans = max(solve(i + 1, j), solve(i, j + 1));
    }
    return ans;
  }

  void dfs(int i, int j, int sz) {
    if (sz == 0) {
      if (us.find(temp) == us.end()) {
        us.insert(temp);
      }
      return;
    }
    for (int ii = i; ii < n; ++ii) {
      for (int jj = j; jj < m; ++jj) {
        if (S[ii] == T[jj]) {
          temp.push_back(S[ii]);
          dfs(ii + 1, jj + 1, sz - 1);
          temp.pop_back();
        }
      }
    }
  }

 public:
  vector<string> all_longest_common_subsequences(string s, string t) {
    // Code here
    n = s.size();
    m = t.size();
    S = s, T = t;
    dp.assign(n, vector<int>(m, -1));
    string ss;
    int sz = solve(0, 0);
    temp.clear();
    us.clear();
    dfs(0, 0, sz);

    vector<string> ans(us.begin(), us.end());
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int T;
  cin >> T;
  while (T--) {
    string s, t;
    cin >> s >> t;
    Solution ob;
    vector<string> ans = ob.all_longest_common_subsequences(s, t);
    for (auto i : ans) cout << i << " ";
    cout << "\n";
  }
  return 0;
}

// } Driver Code Ends
