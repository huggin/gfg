//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  void dfs(int i, vector<int> adj[], vector<int> &v) {
    v[i] = 1;
    for (auto w : adj[i]) {
      if (!v[w]) {
        dfs(w, adj, v);
      }
    }
  }

public:
  int isEularCircuit(int V, vector<int> adj[]) {
    // Code here
    int odd = 0;
    vector<int> visited(V);
    for (int i = 0; i < V; ++i) {
      int degree = 0;
      for (int j = 0; j < adj[i].size(); ++j) {
        ++degree;
      }
      if (degree == 0)
        visited[i] = 1;
      if (degree % 2 != 0) {
        ++odd;
      }
    }
    int part = 0;
    for (int i = 0; i < V; ++i) {
      if (!visited[i]) {
        ++part;
        dfs(i, adj, visited);
      }
    }
    if (part >= 2)
      return 0;
    if (odd > 2)
      return 0;
    if (odd == 2)
      return 1;
    return 2;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    Solution obj;
    int ans = obj.isEularCircuit(V, adj);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code End
