//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  int isNegativeWeightCycle(int n, vector<vector<int>> edges) {
    // Code here
    vector<vector<int>> g(n, vector<int>(n, 100000));
    for (int i = 0; i < edges.size(); ++i) {
      g[edges[i][0]][edges[i][1]] = edges[i][2];
    }

    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (g[i][k] + g[k][j] < g[i][j]) {
            g[i][j] = g[i][k] + g[k][j];
          }
        }
        if (g[i][i] < 0) {
          // cout << i << ' ' << g[i][i] << endl;
          return 1;
        }
      }
    }
    return 0;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++) {
      int x, y, z;
      cin >> x >> y >> z;
      edges.push_back({x, y, z});
    }
    Solution obj;
    int ans = obj.isNegativeWeightCycle(n, edges);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
