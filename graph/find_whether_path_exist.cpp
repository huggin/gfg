//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  // Function to find whether a path exists from the source to destination.
  bool is_Possible(vector<vector<int>> &grid) {
    // code here
    int startx = -1, starty = -1, endx = -1, endy = -1;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[i].size(); ++j) {
        if (grid[i][j] == 1) {
          startx = i;
          starty = j;
        } else if (grid[i][j] == 2) {
          endx = i;
          endy = j;
        }
      }
    }
    if (startx == -1 || endx == -1)
      return 0;
    queue<pair<int, int>> Q;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> v(n, vector<int>(m));
    v[startx][starty] = 1;
    Q.emplace(startx, starty);
    while (!Q.empty()) {
      auto c = Q.front();
      if (c.first == endx && c.second == endy)
        return 1;
      Q.pop();
      for (int i = 0; i < 4; ++i) {
        int x = c.first + dx[i];
        int y = c.second + dy[i];
        if (x == endx && y == endy)
          return 1;
        if (x >= 0 && x < n && y >= 0 && y < m && v[x][y] == 0 &&
            grid[x][y] == 3) {
          v[x][y] = 1;
          Q.emplace(x, y);
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
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> grid[i][j];
      }
    }
    Solution obj;
    bool ans = obj.is_Possible(grid);
    cout << ((ans) ? "1\n" : "0\n");
  }
  return 0;
}
// } Driver Code Ends
