//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct Edge {
  int v, w, c, f;
  Edge(int vv, int ww, int cc) : v(vv), w(ww), c(cc), f(0) {}
  int other(int k) {
    if (k == v) return w;
    return v;
  }
};

class Solution {
  vector<Edge*> edgeTo;
  bool hasPath(vector<Edge*> adj[], int src, int dst) {
    edgeTo.assign(dst + 1, 0);

    vector<int> marked(dst + 1);
    queue<int> Q;
    Q.push(src);
    marked[src] = 1;
    while (!Q.empty()) {
      int c = Q.front();
      Q.pop();
      for (int i = 0; i < adj[c].size(); ++i) {
        Edge* e = adj[c][i];
        int other = e->v;
        if (e->v == c) other = e->w;
        if (e->v == c && !marked[other] && e->f == 0 ||
            e->w == c && !marked[other] && e->f == 1) {
          marked[other] = 1;
          edgeTo[other] = e;
          Q.push(other);
        }
      }
    }
    return marked[dst];
  }

 public:
  int maximumMatch(vector<vector<int>>& G) {
    // Code here
    int m = G.size();
    int n = G[0].size();
    vector<Edge*> adj[m + n + 2];
    for (int i = 1; i <= m; ++i) {
      Edge* e = new Edge(0, i, 1);
      adj[0].push_back(e);
      adj[i].push_back(e);
    }
    for (int j = m + 1; j <= m + n; ++j) {
      Edge* e = new Edge(j, m + n + 1, 1);
      adj[j].push_back(e);
      adj[m + n + 1].push_back(e);
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (G[i][j] == 1) {
          Edge* e = new Edge(i + 1, j + m + 1, 1);
          adj[i + 1].push_back(e);
          adj[j + m + 1].push_back(e);
        }
      }
    }
    int flow = 0;
    while (hasPath(adj, 0, m + n + 1)) {
      ++flow;
      for (int v = m + n + 1; v != 0; v = edgeTo[v]->other(v)) {
        if (edgeTo[v]->v == v)
          edgeTo[v]->f = 0;
        else
          edgeTo[v]->f = 1;
      }
    }
    return flow;
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
