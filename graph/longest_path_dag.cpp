//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  vector<int> post;
  void dfs(int u, vector<pair<int, int>> adj[], vector<int> &marked) {
    marked[u] = 1;
    for (auto w : adj[u]) {
      if (!marked[w.first]) {
        dfs(w.first, adj, marked);
      }
    }
    post.push_back(u);
  }

public:
  vector<int> maximumDistance(vector<vector<int>> edges, int v, int e,
                              int src) {
    // code here
    vector<pair<int, int>> adj[v];
    for (auto c : edges) {
      adj[c[0]].emplace_back(c[1], c[2]);
    }
    post.clear();
    vector<int> marked(v);
    for (int i = 0; i < v; ++i) {
      dfs(i, adj, marked);
    }
    // marked[src] = 1;
    vector<int> dist(v, INT_MIN);
    // cout << INT_MIN << endl;
    dist[src] = 0;
    marked.assign(v, 0);
    reverse(post.begin(), post.end());
    for (int i = 0; i < post.size(); ++i) {
      // cout << post[i] << endl;
      if (dist[post[i]] == INT_MIN) {
        continue;
      } else {
        for (auto w : adj[post[i]]) {
          dist[w.first] = max(dist[post[i]] + w.second, dist[w.first]);
        }
      }
    }

    return dist;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int v, e;
    cin >> v >> e;

    int src;
    cin >> src;
    vector<vector<int>> edges(e, vector<int>(3));
    for (auto &j : edges)
      cin >> j[0] >> j[1] >> j[2];

    Solution s;
    vector<int> ans = s.maximumDistance(edges, v, e, src);
    for (auto j : ans) {
      if (j == INT_MIN)
        cout << "INF ";
      else
        cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}
// } Driver Code Ends
