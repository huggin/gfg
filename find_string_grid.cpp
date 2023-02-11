//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  bool ok(vector<vector<char>>& g, int i, int j, const string& w) {
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int n = w.size();
    for (int k = 0; k < 8; ++k) {
      int ni = i + dx[k] * (n - 1);
      int nj = j + dy[k] * (n - 1);
      if (ni >= 0 && ni < g.size() && nj >= 0 && nj < g[0].size()) {
        int l = 0;
        for (; l < n; ++l) {
          if (w[l] != g[i + dx[k] * l][j + dy[k] * l]) {
            break;
          }
        }
        if (l == n) return true;
      }
    }
    return false;
  }

 public:
  vector<vector<int>> searchWord(vector<vector<char>> grid, string word) {
    // Code here
    vector<vector<int>> ans;

    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[i].size(); ++j) {
        if (grid[i][j] == word[0] && ok(grid, i, j, word)) {
          ans.push_back(vector<int>{i, j});
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
    vector<vector<char>> grid(n, vector<char>(m, 'x'));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) cin >> grid[i][j];
    }
    string word;
    cin >> word;
    Solution obj;
    vector<vector<int>> ans = obj.searchWord(grid, word);
    for (auto i : ans) {
      for (auto j : i) cout << j << " ";
      cout << "\n";
    }
    if (ans.size() == 0) {
      cout << "-1\n";
    }
  }
  return 0;
}
// } Driver Code Ends
