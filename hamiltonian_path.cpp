//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  int v[11];
  int n, m;
  bool solve(int k, vector<vector<int>>& g, int u) {
    if (u == n) return true;
    for (int i = 0; i < n; ++i) {
      if (g[k][i] == 1 && v[i] == 0) {
        v[i] = 1;
        if (solve(i, g, u + 1)) return true;
        v[i] = 0;
      }
    }
    return false;
  }

 public:
  bool check(int N, int M, vector<vector<int>> Edges) {
    // code here
    vector<vector<int>> g(N, vector<int>(N));
    n = N;
    m = M;
    for (int i = 0; i < M; ++i) {
      g[Edges[i][0] - 1][Edges[i][1] - 1] = 1;
      g[Edges[i][1] - 1][Edges[i][0] - 1] = 1;
    }
    for (int i = 0; i < N; ++i) {
      memset(v, 0, sizeof(v));
      v[i] = 1;
      if (solve(i, g, 1)) return true;
    }
    return false;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N, M, X, Y;
    cin >> N >> M;
    vector<vector<int>> Edges;
    for (int i = 0; i < M; i++) {
      cin >> X >> Y;
      Edges.push_back({X, Y});
    }
    Solution obj;
    if (obj.check(N, M, Edges)) {
      cout << "1" << endl;
    } else
      cout << "0" << endl;
  }
}
// } Driver Code Ends
