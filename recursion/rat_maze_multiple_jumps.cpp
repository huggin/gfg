//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  vector<vector<int>> M;
  int N;
  vector<vector<int>> ans;

  bool solve(int i, int j, vector<pair<int, int>>& p, int d) {
    if (i == N - 1 && j == N - 1) {
      ans.assign(N, vector<int>(N));
      ans[0][0] = ans[N - 1][N - 1] = 1;
      for (int k = 0; k < p.size(); ++k) {
        ans[p[k].first][p[k].second] = 1;
      }

      return true;
    }
    if (M[i][j] == 0) return false;
    p.emplace_back(i, j);

    for (int k = 1; k <= M[i][j]; ++k) {
      if (j + k < N)
        if (solve(i, j + k, p, d + 1)) return true;
      if (i + k < N)
        if (solve(i + k, j, p, d + 1)) return true;
    }
    p.pop_back();
    return false;
  }

 public:
  vector<vector<int>> ShortestDistance(vector<vector<int>>& matrix) {
    // Code here
    N = matrix.size();
    M = matrix;

    vector<pair<int, int>> path;

    if (!solve(0, 0, path, 0)) return vector<vector<int>>{vector<int>{-1}};

    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> matrix[i][j];
      }
    }
    Solution obj;
    vector<vector<int>> ans = obj.ShortestDistance(matrix);
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
