//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  vector<vector<int>> nearest(vector<vector<int>> grid) {
    // Code here
    vector<vector<int>> ans = grid;
    int n = grid.size();
    int m = grid[0].size();
    queue<int> Q;
    vector<vector<int>> v(grid);
    for (int i = 0; i < n; ++i) {
      v[i].assign(m, 0);
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 1) {
          ans[i][j] = 0;
          Q.push(i);
          Q.push(j);
          Q.push(0);
          v[i][j] = 1;
        } else {
          ans[i][j] = 2000;
        }
      }
    }
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};
    while (!Q.empty()) {
      int x = Q.front();
      Q.pop();
      int y = Q.front();
      Q.pop();
      int c = Q.front();
      Q.pop();
      for (int k = 0; k < 4; ++k) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || v[nx][ny] == 1) continue;
        if (grid[nx][ny] == 1) continue;
        v[nx][ny] = 1;
        Q.push(nx);
        Q.push(ny);
        Q.push(c + 1);
        ans[nx][ny] = c + 1;
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> grid[i][j];
      }
    }
    Solution obj;
    vector<vector<int>> ans = obj.nearest(grid);
    for (auto i : ans) {
      for (auto j : i) {
        cout << j << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}
// } Driver Code Ends
