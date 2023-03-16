//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct Edge {
  int from, to;
  int f;
  Edge(int v1, int v2) : from(v1), to(v2), f(0) {}

  int other(int vertex) {
    if (from == vertex) return to;
    return from;
  }
};

class Solution {
  vector<Edge*> path;
  int n;

  bool hasAugment(vector<Edge*> adj[]) {
    vector<int> marked(n);
    queue<int> Q;
    Q.push(0);
    marked[0] = 1;
    while (!Q.empty()) {
      int c = Q.front();
      if (c == n - 1) return true;
      Q.pop();
      for (Edge* e : adj[c]) {
        int o = e->other(c);
        if (marked[o]) continue;
        if (o == e->from && e->f == 1 || o == e->to && e->f == 0) {
          Q.push(o);
          marked[o] = 1;
          path[o] = e;
        }
      }
    }
    return false;
  }

 public:
  int maximumMatch(vector<vector<int>>& G) {
    // Code here
    int m = G.size();
    int n = G[0].size();
    this->n = m + n + 2;

    vector<Edge*> adj[m + n + 2];
    for (int i = 1; i <= m; ++i) {
      Edge* e = new Edge(0, i);
      adj[0].push_back(e);
      adj[i].push_back(e);
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (G[i][j] == 1) {
          Edge* e = new Edge(i + 1, j + m + 1);
          adj[i + 1].push_back(e);
          adj[j + m + 1].push_back(e);
        }
      }
    }
    for (int i = m + 1; i < m + n + 1; ++i) {
      Edge* e = new Edge(i, m + n + 1);
      adj[i].push_back(e);
      adj[m + n + 1].push_back(e);
    }

    int ans = 0;
    path.assign(this->n, nullptr);
    while (hasAugment(adj)) {
      ++ans;
      for (int t = m + n + 1; t != 0; t = path[t]->other(t)) {
        if (path[t]->f == 0) {
          path[t]->f = 1;
        } else {
          path[t]->f = 0;
        }
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
    int m, n;
    cin >> m >> n;
    vector<vector<int>> G(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) cin >> G[i][j];
    }
    Solution obj;
    int ans = obj.maximumMatch(G);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
