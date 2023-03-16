//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
 public:
  int MinimumWalk(vector<vector<int>>& graph, int u, int v, int k) {
    // Code here
    int n = graph.size();
    vector<vector<int>> dp(n, vector<int>(n));
    dp[u][0] = 1;
    for (int i = 1; i <= k; ++i) {
      for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
          if (graph[x][y] && dp[x][i - 1]) {
            dp[y][i] += dp[x][i - 1];
          }
        }
      }
    }
    return dp[v][k];
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> graph[i][j];
      }
    }
    int u, v, k;
    cin >> u >> v >> k;
    Solution obj;
    int ans = obj.MinimumWalk(graph, u, v, k);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends

