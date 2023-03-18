//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  int n, m;
  vector<vector<char>> b;
  string t;
  int ans;
  vector<vector<char>> marked;

  void solve(int i, int j, int k) {
    if (k == t.size() - 1) {
      ++ans;
      return;
    }

    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    for (int l = 0; l < 4; ++l) {
      int ni = i + dx[l];
      int nj = j + dy[l];
      if (ni >= 0 && ni < n && nj >= 0 && nj < m && !marked[ni][nj] &&
          b[ni][nj] == t[k + 1]) {
        marked[ni][nj] = 1;
        solve(ni, nj, k + 1);
        marked[ni][nj] = 0;
      }
    }
  }

 public:
  int findOccurrence(vector<vector<char>> &mat, string target) {
    n = mat.size();
    m = mat[0].size();
    b = mat;
    t = target;
    marked.assign(n, vector<char>(m));
    ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (mat[i][j] == target[0]) {
          marked[i][j] = 1;
          solve(i, j, 0);
          marked[i][j] = 0;
        }
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int R, C;
    cin >> R >> C;
    vector<vector<char>> mat(R);
    for (int i = 0; i < R; i++) {
      mat[i].resize(C);
      for (int j = 0; j < C; j++) cin >> mat[i][j];
    }
    string target;
    cin >> target;
    Solution obj;
    cout << obj.findOccurrence(mat, target) << endl;
  }
}

// } Driver Code Ends
