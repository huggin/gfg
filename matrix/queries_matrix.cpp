//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  vector<vector<int>> solveQueries(int n, vector<vector<int>> Queries) {
    // Code here
    vector<vector<int>> ans(n, vector<int>(n));
    for (auto& q : Queries) {
      for (int i = q[0]; i <= q[2]; ++i) ans[i][q[1]]++;
      if (q[3] + 1 < n) {
        for (int i = q[0]; i <= q[2]; ++i) {
          ans[i][q[3] + 1]--;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 1; j < n; ++j) {
        ans[i][j] += ans[i][j - 1];
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
    int n, q;
    cin >> n >> q;
    vector<vector<int>> Queries;
    for (int i = 0; i < q; i++) {
      vector<int> cur(4);
      for (int j = 0; j < 4; j++) cin >> cur[j];
      Queries.push_back(cur);
    }
    Solution obj;
    vector<vector<int>> ans = obj.solveQueries(n, Queries);
    for (auto i : ans) {
      for (auto j : i) cout << j << " ";
      cout << "\n";
    }
  }
  return 0;
}
// } Driver Code Ends
