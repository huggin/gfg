//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  unordered_map<int, unordered_map<int, int>> dp;

  void dfs(vector<vector<int>> &g, int u, int p, vector<int> &parent) {
    parent[u] = p;
    for (int v : g[u]) {
      if (v == p)
        continue;
      dfs(g, v, u, parent);
    }
  }

  int solve(const vector<int> &parent, const vector<int> &q) {
    int a = q[0];
    int b = q[1];
    if (dp.find(a) != dp.end() && dp[a].find(b) != dp[a].end()) {
      return dp[a][b];
    }
    int &ans = dp[a][b];
    while (a != -1) {
      if (a != b) {
        a = parent[a];
      } else {
        return ans = 1;
      }
    }
    return ans = 0;
  }

public:
  vector<string> isInSubtree(vector<vector<int>> &g, int n, int q,
                             vector<vector<int>> queries) {
    // code here
    vector<string> ans(q);
    vector<int> parent(n + 1);
    dfs(g, 1, -1, parent);

    for (int i = 0; i < q; i++) {
      ans[i] = (solve(parent, queries[i]) ? "YES" : "NO");
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
      int a, b;
      cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    int q;
    cin >> q;
    vector<vector<int>> queries(q, vector<int>(2));
    for (auto &j : queries)
      cin >> j[0] >> j[1];

    Solution s;
    vector<string> ans = s.isInSubtree(g, n, q, queries);
    for (auto j : ans)
      cout << j << endl;
  }
  return 0;
}
// } Driver Code Ends
