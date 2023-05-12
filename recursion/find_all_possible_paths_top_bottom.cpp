//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  vector<vector<int>> ans;
  vector<vector<int>> g;
  void go(int i, int j, int n, int m, vector<int> &v) {
    if (i == n - 1 && j == m - 1) {
      v.push_back(g[i][j]);
      ans.push_back(v);
      v.pop_back();
      return;
    }
    if (i < n - 1) {
      v.push_back(g[i][j]);
      go(i + 1, j, n, m, v);
      v.pop_back();
    }
    if (j < m - 1) {
      v.push_back(g[i][j]);
      go(i, j + 1, n, m, v);
      v.pop_back();
    }
  }

public:
  vector<vector<int>> findAllPossiblePaths(int n, int m,
                                           vector<vector<int>> &grid) {
    // code here
    ans.clear();
    g = grid;
    vector<int> v;
    go(0, 0, n, m, v);
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
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> grid[i][j];
      }
    }
    Solution ob;
    auto ans = ob.findAllPossiblePaths(n, m, grid);
    for (int i = 0; i < ans.size(); i++) {
      for (int j = 0; j < ans[i].size(); j++) {
        cout << ans[i][j] << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}

// } Driver Code Ends
