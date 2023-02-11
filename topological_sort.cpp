//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  vector<int> visited;
  vector<int> post;
  vector<int> ans;

  void dfs(int v, vector<int> adj[]) {
    visited[v] = 1;
    for (auto w : adj[v]) {
      if (!visited[w]) {
        dfs(w, adj);
      }
    }
    post.push_back(v);
  }

 public:
  // Function to return list containing vertices in Topological order.
  vector<int> topoSort(int V, vector<int> adj[]) {
    // code here
    visited.assign(V, 0);
    for (int i = 0; i < V; ++i) {
      if (!visited[i]) {
        dfs(i, adj);
      }
    }
    reverse(post.begin(), post.end());

    return post;
  }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<int> adj[]) {
  if (V != res.size()) return 0;

  vector<int> map(V, -1);
  for (int i = 0; i < V; i++) {
    map[res[i]] = i;
  }
  for (int i = 0; i < V; i++) {
    for (int v : adj[i]) {
      if (map[i] > map[v]) return 0;
    }
  }
  return 1;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N, E;
    cin >> E >> N;
    int u, v;

    vector<int> adj[N];

    for (int i = 0; i < E; i++) {
      cin >> u >> v;
      adj[u].push_back(v);
    }

    Solution obj;
    vector<int> res = obj.topoSort(N, adj);

    cout << check(N, res, adj) << endl;
  }

  return 0;
}
// } Driver Code End
