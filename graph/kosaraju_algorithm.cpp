//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  vector<int> post;
  vector<int> v;

  void dfs(int i, vector<int> adj[]) {
    v[i] = 1;
    for (auto w : adj[i]) {
      if (!v[w]) {
        dfs(w, adj);
      }
    }
    post.push_back(i);
  }

  void dfs2(int i, vector<int> adj[]) {
    v[i] = 1;
    for (auto w : adj[i]) {
      if (!v[w]) {
        dfs2(w, adj);
      }
    }
  }

public:
  // Function to find number of strongly connected components in the graph.
  int kosaraju(int V, vector<int> adj[]) {
    // code here
    vector<int> radj[V];
    for (int i = 0; i < V; ++i) {
      for (int j = 0; j < adj[i].size(); ++j) {
        radj[adj[i][j]].push_back(i);
      }
    }

    v.assign(V, 0);
    for (int i = 0; i < V; ++i) {
      if (!v[i]) {
        dfs(i, radj);
      }
    }

    v.assign(V, 0);
    int ans = 0;

    for (int i = V - 1; i >= 0; --i) {
      if (!v[post[i]]) {
        ++ans;
        dfs2(post[i], adj);
      }
    }
    return ans;
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
    cout << obj.kosaraju(V, adj) << "\n";
  }

  return 0;
}

// } Driver Code Ends
