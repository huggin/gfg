//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  void dfs(int v, vector<vector<int>>& adj, vector<int>& post,
           vector<int>& marked) {
    marked[v] = 1;
    for (auto w : adj[v]) {
      if (!marked[w]) {
        dfs(w, adj, post, marked);
      }
    }
    post.push_back(v);
  }

 public:
  int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
    // code here
    vector<int> marked(V + 1);
    int ans = 0;
    for (int i = 1; i <= V; ++i) {
      if (!marked[i]) {
        vector<int> post;
        dfs(i, adj, post, marked);
        int j = 0;
        for (j = 0; j < post.size(); ++j) {
          if (adj[post[j]].size() != post.size() - 1) break;
        }
        if (j == post.size()) ++ans;
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
    int E, V;
    cin >> E >> V;
    vector<vector<int>> adj(V + 1, vector<int>());
    for (int i = 0; i < E; i++) {
      int u, v;

      cin >> u >> v;

      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    Solution obj;

    int res = obj.findNumberOfGoodComponent(V, adj);
    cout << res << "\n";
  }
  return 0;
}
// } Driver Code Ends
