//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  // Function to return the minimum cost to react at bottom
  // right cell from top left cell.
  int minimumCostPath(vector<vector<int>>& grid) {
    // Code here
    int n = grid.size();
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    vector<vector<int>> v(n, vector<int>(n));
    v[0][0] = 1;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        Q;

    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};

    Q.emplace(grid[0][0], make_pair(0, 0));
    while (!Q.empty()) {
      auto c = Q.top();
      Q.pop();
      int x = c.second.first;
      int y = c.second.second;

      dist[x][y] = c.first;
      if (x == n - 1 && y == n - 1) return dist[x][y];
      for (int k = 0; k < 4; ++k) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && !v[nx][ny]) {
          v[nx][ny] = 1;
          Q.emplace(dist[x][y] + grid[nx][ny], make_pair(nx, ny));
        }
      }
    }
    return dist[n - 1][n - 1];
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> grid[i][j];
      }
    }
    Solution obj;
    int ans = obj.minimumCostPath(grid);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
