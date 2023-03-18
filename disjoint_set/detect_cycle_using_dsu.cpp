//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  int root(int i, vector<int>& p) {
    while (i != p[i]) {
      p[i] = p[p[i]];
      i = p[i];
    }
    return i;
  }
  bool connected(int i, int j, vector<int>& p) {
    int r1 = root(i, p);
    int r2 = root(j, p);
    return r1 == r2;
  }
  void connect(int i, int j, vector<int>& p) {
    int r1 = root(i, p);
    int r2 = root(j, p);
    p[r1] = r2;
  }

 public:
  // Function to detect cycle using DSU in an undirected graph.
  int detectCycle(int V, vector<int> adj[]) {
    // Code here
    vector<int> p(V);
    for (int i = 0; i < V; ++i) {
      p[i] = i;
    }
    for (int i = 0; i < V; ++i) {
      for (int j = 0; j < adj[i].size(); ++j) {
        // cout << i << ' ' << adj[i][j] << endl;
        if (adj[i][j] < i) continue;
        if (connected(i, adj[i][j], p)) {
          return 1;
        } else {
          connect(i, adj[i][j], p);
        }
      }
    }
    return 0;
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
    int ans = obj.detectCycle(V, adj);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
