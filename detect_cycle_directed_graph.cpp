//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  vector<int> visited;
  vector<int> onStack;
  bool cycle;

  void dfs(int v, vector<int> adj[]) {
    if (cycle) return;
    visited[v] = 1;
    onStack[v] = 1;
    for (auto w : adj[v]) {
      if (!visited[w]) {
        dfs(w, adj);
      } else if (onStack[w]) {
        cycle = true;
      }
    }
    onStack[v] = 0;
  }

 public:
  // Function to detect cycle in a directed graph.
  bool isCyclic(int V, vector<int> adj[]) {
    // code here
    visited.assign(V, 0);
    onStack.assign(V, 0);
    cycle = false;
    for (int i = 0; i < V; ++i) {
      if (!visited[i]) {
        dfs(i, adj);
      }
    }
    return cycle;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for (int i = 0; i < E; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
    }

    Solution obj;
    cout << obj.isCyclic(V, adj) << "\n";
  }

  return 0;
}

// } Driver Code Ends
