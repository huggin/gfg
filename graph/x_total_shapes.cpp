//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  // Function to find the number of 'X' total shapes.
  int xShape(vector<vector<char>>& grid) {
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> v(n, vector<int>(m));
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 'X' && !v[i][j]) {
          ++ans;
          queue<int> Q;
          Q.push(i);
          Q.push(j);
          v[i][j] = 1;
          while (!Q.empty()) {
            int x = Q.front();
            Q.pop();
            int y = Q.front();
            Q.pop();
            for (int k = 0; k < 4; ++k) {
              int nx = x + dx[k];
              int ny = y + dy[k];
              if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                  grid[nx][ny] == 'X' && !v[nx][ny]) {
                v[nx][ny] = 1;
                Q.push(nx);
                Q.push(ny);
              }
            }
          }
        }
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
    vector<vector<char>> grid(n, vector<char>(m, '#'));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> grid[i][j];
      }
    }
    Solution obj;
    int ans = obj.xShape(grid);
    cout << ans << '\n';
  }
  return 0;
}
// } Driver Code Ends
