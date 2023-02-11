class Solution {
  vector<int> parent, children, low, marked;
  int count;
  vector<int> ans;
  void dfs(int u, vector<int> adj[]) {
    marked[u] = count++;
    low[u] = marked[u];
    for (int v : adj[u]) {
      if (parent[u] == v) continue;
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

    if (ans.size() == 0) return vector<int>{-1};
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    return ans;
  }
};
