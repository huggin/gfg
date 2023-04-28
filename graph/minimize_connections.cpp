//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  vector<int> marked;
  void dfs(vector<vector<int>> &g, int n, int k) {
    marked[k] = 1;
    for (int i = 0; i < n; ++i) {
      if (g[k][i] == 1 && !marked[i])
        dfs(g, n, i);
    }
  }

public:
  int minimumConnections(vector<vector<int>> &c, int n) {
    // code here
    vector<vector<int>> g(n, vector<int>(n, 0));
    for (int i = 0; i < c.size(); ++i) {
      g[c[i][0]][c[i][1]] = 1;
      g[c[i][1]][c[i][0]] = 1;
    }
    int count = 0;
    marked.assign(n, 0);
    for (int i = 0; i < n; ++i) {
      if (marked[i] == 0) {
        dfs(g, n, i);
        ++count;
      }
    }
    // cout << "count=" << count << endl;
    if (count == 1)
      return 0;
    if (c.size() >= n - 1)
      return count - 1;
    return -1;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> c(m, vector<int>(2));
    for (auto &j : c)
      cin >> j[0] >> j[1];
    Solution s;
    cout << s.minimumConnections(c, n) << endl;
  }
  return 0;
}
// } Driver Code Ends
