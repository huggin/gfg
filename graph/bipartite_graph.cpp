//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  vector<int> visited;
  vector<int> color;
  bool ans;

  void dfs(int v, vector<int> adj[]) {
    if (!ans)
      return;
    visited[v] = 1;
    for (auto w : adj[v]) {
      if (!visited[w]) {
        color[w] = !color[v];
        dfs(w, adj);
      } else if (color[w] == color[v]) {
        ans = false;
      }
    }
  }

public:
  bool isBipartite(int V, vector<int> adj[]) {
    // Code here
    ans = true;
    visited.assign(V, 0);
    color.assign(V, 0);
    for (int i = 0; i < V; ++i) {
      if (!visited[i]) {
        color[i] = 0;
        dfs(i, adj);
      }
    }
    return ans;
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
    bool ans = obj.isBipartite(V, adj);
    if (ans)
      cout << "1\n";
    else
      cout << "0\n";
  }
  return 0;
}
// } Driver Code Ends
