//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  vector<int> marked;
  vector<int> post;

  void dfs(int k, vector<vector<int>> &g) {
    marked[k] = 1;
    for (int i = 0; i < g[k].size(); ++i) {
      if (g[k][i] && !marked[i]) {
        dfs(i, g);
      }
    }
    post.push_back(k);
  }

public:
  int possible_paths(vector<vector<int>> edges, int n, int s, int d) {
    // Code here
    vector<vector<int>> g(n, vector<int>(n));
    for (auto &e : edges) {
      g[e[0]][e[1]] = 1;
    }
    marked.assign(n, 0);
    for (int i = 0; i < n; ++i) {
      if (!marked[i]) {
        dfs(i, g);
      }
    }
    vector<int> dist(n, 0);
    dist[s] = 1;
    for (int i = n - 1; i >= 0; --i) {
      for (int j = i - 1; j >= 0; --j) {
        if (g[post[i]][post[j]]) {
          dist[post[j]] += dist[post[i]];
        }
      }
    }
    return dist[d];
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m, s, d;
    cin >> n >> m >> s >> d;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      edges.push_back({u, v});
    }
    Solution obj;
    int ans = obj.possible_paths(edges, n, s, d);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
