//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  int n, m;
  bool found;
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};
  vector<vector<int>> marked;

  void solve(const vector<vector<char>>& mat, int i, int j, const string& w,
             int k) {
    if (found) return;
    if (k == w.size() - 1) {
      found = true;
      return;
    }
    for (int d = 0; d < 4; ++d) {
      int ni = i + dx[d];
      int nj = j + dy[d];
      if (ni >= 0 && ni < n && nj >= 0 && nj < m && mat[ni][nj] == w[k + 1] &&
          !marked[ni][nj]) {
        marked[ni][nj] = 1;
        solve(mat, ni, nj, w, k + 1);
        marked[ni][nj] = 0;
      }
    }
  }

 public:
  bool wordSearch(vector<vector<char>>& mat, string w) {
    // code here
    n = mat.size();
    m = mat[0].size();
    found = false;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (mat[i][j] == w[0]) {
          marked.assign(n, vector<int>(m));
          marked[i][j] = 1;
          solve(mat, i, j, w, 0);
          if (found) return true;
        }
      }
    }
    return false;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> mat[i][j];
      }
    }
    string str;
    cin >> str;
    Solution ob;
    auto ans = ob.wordSearch(mat, str);
    cout << ans << "\n";
  }
  return 0;
}

// } Driver Code Ends
