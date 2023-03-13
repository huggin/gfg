//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  vector<int> dp[2];

  int solve(vector<int> adj[], int v, int used, int prev) {
    if (dp[used][v] != -1) return dp[used][v];
    int& ans = dp[used][v];
    ans = 0;
    for (auto w : adj[v]) {
      if (w == prev) continue;
      if (!used)
        ans += 1 + solve(adj, w, 1, v);
      else
        ans += min(solve(adj, w, 0, v), 1 + solve(adj, w, 1, v));
    }

    return ans;
  }

 public:
  int countVertex(int N, vector<vector<int>> edges) {
    // code here
    vector<int> adj[N];
    for (auto& e : edges) {
      adj[e[0] - 1].push_back(e[1] - 1);
      adj[e[1] - 1].push_back(e[0] - 1);
    }
    dp[0].assign(N, -1);
    dp[1].assign(N, -1);

    return min(solve(adj, 0, 0, -1), 1 + solve(adj, 0, 1, -1));
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    vector<vector<int>> edges;
    for (int i = 0; i < N - 1; i++) {
      int x, y;
      cin >> x >> y;
      vector<int> edge;
      edge.push_back(x);
      edge.push_back(y);
      edges.push_back(edge);
    }

    Solution ob;
    cout << ob.countVertex(N, edges) << endl;
  }
  return 0;
}
// } Driver Code Ends
