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
