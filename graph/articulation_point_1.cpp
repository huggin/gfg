//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  vector<int> parent, children, low, marked;
  int count;
  vector<int> ans;
  void dfs(int u, vector<int> adj[]) {
    marked[u] = count++;
    low[u] = marked[u];
    for (int v : adj[u]) {
      if (parent[u] == v)
        continue;
      if (!marked[v]) {
        children[u]++;
        parent[v] = u;
        dfs(v, adj);

        low[u] = min(low[u], low[v]);

        if (low[v] >= marked[u] && parent[u] != -1) {
          ans.push_back(u);
        }
      } else {
        low[u] = min(low[u], marked[v]);
      }
    }
  }

public:
  vector<int> articulationPoints(int V, vector<int> adj[]) {
    // Code here
    parent.assign(V, -1);
    children.assign(V, 0);
    low.assign(V, 0);
    marked.assign(V, 0);
    count = 1;
    ans.clear();
    dfs(0, adj);
    if (children[0] > 1) {
      ans.push_back(0);
    }

    if (ans.size() == 0)
      return vector<int>{-1};
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
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
    vector<int> ans = obj.articulationPoints(V, adj);
    for (auto i : ans)
      cout << i << " ";
    cout << "\n";
  }
  return 0;
}
// } Driver Code Ends
