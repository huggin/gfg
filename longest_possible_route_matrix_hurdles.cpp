//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  int ans = -1;
  int x, y;
  vector<vector<char>> v;
  int dx[4] = {-1, 0, 0, 1};
  int dy[4] = {0, -1, 1, 0};
  void solve(vector<vector<int>>& m, int xc, int yc, int k) {
    // cout << xc << ' ' << yc << ' ' << k << endl;
    if (xc == x && yc == y) {
      ans = max(ans, k);
      return;
    }
    for (int i = 0; i < 4; ++i) {
      int nx = xc + dx[i];
      int ny = yc + dy[i];
      if (nx >= 0 && nx < m.size() && ny >= 0 && ny < m[0].size() &&
          v[nx][ny] == 0 && m[nx][ny] != 0) {
        v[nx][ny] = 1;
        solve(m, nx, ny, k + 1);
        v[nx][ny] = 0;
      }
    }
  }

 public:
  int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd) {
    // code here
    if (matrix[xs][ys] == 0 || matrix[xd][yd] == 0) return -1;
    v.assign(matrix.size(), vector<char>(matrix[0].size()));
    x = xd;
    y = yd;
    v[xs][ys] = 1;
    solve(matrix, xs, ys, 0);
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
    int xs, ys, xd, yd;
    cin >> xs >> ys >> xd >> yd;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> mat[i][j];
      }
    }
    Solution ob;
    int ans = ob.longestPath(mat, xs, ys, xd, yd);
    cout << ans;
    cout << "\n";
  }
  return 0;
}
// } Driver Code Ends
