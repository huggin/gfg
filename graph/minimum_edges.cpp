//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  int solve(vector<int> adj[], vector<int> adj2[], int n, int src, int dst) {
    queue<int> Q;
    vector<int> v(n + 1);
    Q.push(src);
    v[src] = 1;
    int k = 1;
    while (true) {
      while (!Q.empty()) {
        int c = Q.front();
        Q.pop();
        for (auto w : adj[c]) {
          if (!v[w]) {
            v[w] = v[c];
            Q.push(w);
          }
        }
      }

      if (v[dst] != 0)
        return v[dst] - 1;
      for (int i = 1; i <= n; ++i) {
        if (v[i] == k) {
          for (auto w : adj2[i]) {
            if (v[w] == 0) {
              v[w] = k + 1;
              Q.push(w);
            }
          }
        }
      }
      k++;
      if (Q.empty())
        break;
    }
    return -1;
  }

public:
  int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {
    vector<int> adj[n + 1];
    vector<int> adj2[n + 1];
    for (int i = 0; i < edges.size(); ++i) {
      adj[edges[i][0]].push_back(edges[i][1]);
      adj2[edges[i][1]].push_back(edges[i][0]);
    }
    int ans = solve(adj, adj2, n, src, dst);

    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(2));
    for (auto &j : edges)
      for (auto &i : j)
        cin >> i;
    int src, dst;
    cin >> src >> dst;
    Solution s;
    cout << s.minimumEdgeReversal(edges, n, src, dst) << endl;
  }
  return 0;
}
// } Driver Code Ends
