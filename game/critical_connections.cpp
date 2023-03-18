//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  vector<int> low, dist, onStack, marked, to;

  vector<vector<int>> ans;
  stack<int> S;
  int count;

  void dfs(int v, vector<int> adj[]) {
    marked[v] = 1;
    onStack[v] = 1;
    dist[v] = count++;
    low[v] = dist[v];
    for (auto w : adj[v]) {
      if (!marked[w]) {
        to[w] = v;
        dfs(w, adj);
        low[v] = min(low[v], low[w]);
      } else if (w != to[v] && onStack[w]) {
        low[v] = min(low[v], dist[w]);
      }
    }
    onStack[v] = 0;
    if (low[v] == dist[v]) {
      if (to[v] != -1) {
        ans.push_back(vector<int>{min(v, to[v]), max(v, to[v])});
      }
    }
  }

public:
  vector<vector<int>> criticalConnections(int V, vector<int> adj[]) {
    // Code here
    marked.assign(V, 0);
    onStack.assign(V, 0);
    low.assign(V, 0);
    dist.assign(V, 0);
    to.assign(V, -1);
    count = 0;

    for (int i = 0; i < V; ++i) {
      if (!marked[i]) {
        dfs(i, adj);
      }
    }
    sort(ans.begin(), ans.end());
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
    vector<vector<int>> ans = obj.criticalConnections(V, adj);

    for (int i = 0; i < ans.size(); i++)
      cout << ans[i][0] << " " << ans[i][1] << endl;
  }
  return 0;
}
// } Driver Code Ends
