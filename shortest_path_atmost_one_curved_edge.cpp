//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

struct edge {
  int v, w;
  int s, c;

  edge(int a, int b, int v1, int v2) : v(a), w(b), s(v1), c(v2) {}

  int other(int vertex) {
    if (v == vertex) return w;
    return v;
  }
};

class Solution {
 public:
  int shortestPath(int n, int m, int a, int b, vector<vector<int>>& edges) {
    // code here
    vector<edge*> adj[n];
    for (auto& e : edges) {
      edge* ed = new edge(e[0] - 1, e[1] - 1, e[2], e[3]);
      adj[e[0] - 1].push_back(ed);
      adj[e[1] - 1].push_back(ed);
    }

    int src = a - 1, dst = b - 1;
    vector<int> dist[2];
    dist[0].assign(n, INT_MAX);
    dist[1].assign(n, INT_MAX);
    dist[0][src] = 0;
    dist[1][src] = 0;

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<tuple<int, int, int>>>
        Q;

    Q.emplace(0, 0, src);
    while (!Q.empty()) {
      auto c = Q.top();
      Q.pop();
      int d = get<0>(c);
      int used = get<1>(c);
      int v = get<2>(c);
      if (v == dst) return d;

      for (auto e : adj[v]) {
        int w = e->other(v);
        if (used) {
          if (d + e->s < dist[1][w]) {
            dist[1][w] = d + e->s;
            Q.emplace(d + e->s, 1, w);
          }
        } else {
          if (d + e->s < dist[0][w]) {
            dist[0][w] = d + e->s;
            Q.emplace(d + e->s, 0, w);
          }
          if (d + e->c < dist[1][w]) {
            dist[1][w] = d + e->c;
            Q.emplace(d + e->c, 1, w);
          }
        }
      }
    }

    return -1;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, a, b;
    cin >> n >> m;
    cin >> a >> b;

    vector<vector<int>> edges;

    for (int i = 0; i < m; i++) {
      int u, v, x, y;
      cin >> u >> v >> x >> y;
      edges.push_back({u, v, x, y});
    }

    Solution ob;
    cout << ob.shortestPath(n, m, a, b, edges) << endl;
  }
  return 0;
}
// } Driver Code Ends
