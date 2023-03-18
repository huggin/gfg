//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  vector<int> v;
  vector<int> on;
  bool cycle;
  vector<int> post;

  void dfs(int i, vector<int> adj[]) {
    if (cycle) return;
    v[i] = 1;
    on[i] = 1;
    for (auto w : adj[i]) {
      if (!v[w]) {
        dfs(w, adj);
      } else if (on[w]) {
        cycle = true;
      }
    }
    post.push_back(i);
    on[i] = 0;
  }

 public:
  vector<int> findOrder(int n, int m, vector<vector<int>> p) {
    // code here
    vector<int> adj[n];
    for (int i = 0; i < m; ++i) {
      adj[p[i][1]].push_back(p[i][0]);
    }
    v.assign(n, 0);
    on.assign(n, 0);
    cycle = false;
    for (int i = 0; i < n; ++i) {
      if (!v[i]) {
        dfs(i, adj);
      }
    }
    if (cycle) return vector<int>{};
    reverse(post.begin(), post.end());
    return post;
  }
};

//{ Driver Code Starts.

int check(int V, vector<int> &res, vector<int> adj[]) {
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
    int n, m;
    cin >> n >> m;
    int u, v;

    vector<vector<int>> prerequisites;

    for (int i = 0; i < m; i++) {
      cin >> u >> v;
      prerequisites.push_back({u, v});
    }

    vector<int> adj[n];
    for (auto pre : prerequisites) adj[pre[1]].push_back(pre[0]);

    Solution obj;
    vector<int> res = obj.findOrder(n, m, prerequisites);
    if (!res.size())
      cout << "No Ordering Possible" << endl;
    else
      cout << check(n, res, adj) << endl;
  }

  return 0;
}
// } Driver Code Ends
