//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  vector<int> color;
  int n;

  bool ok(int k, bool g[101][101], int c) {
    for (int i = 0; i < n; ++i) {
      if (k == i) continue;
      if (!g[k][i]) continue;
      if (color[i] == c) return false;
    }
    return true;
  }

  bool dfs(int k, bool g[101][101], int M) {
    if (k == n) return true;
    for (int i = 0; i < M; ++i) {
      if (ok(k, g, i)) {
        color[k] = i;
        bool flag = dfs(k + 1, g, M);
        if (!flag) {
          color[k] = -1;
        } else {
          return true;
        }
      }
    }
    return false;
  }

 public:
  // Function to determine if graph can be coloured with at most M colours such
  // that no two adjacent vertices of graph are coloured with same colour.
  bool graphColoring(bool g[101][101], int M, int N) {
    // your code here
    color.assign(N, -1);
    n = N;
    return dfs(0, g, M);
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, e;
    cin >> n >> m >> e;
    int i;
    bool graph[101][101];
    for (i = 0; i < n; i++) {
      memset(graph[i], 0, sizeof(graph[i]));
    }
    for (i = 0; i < e; i++) {
      int a, b;
      cin >> a >> b;
      graph[a - 1][b - 1] = 1;
      graph[b - 1][a - 1] = 1;
    }
    Solution ob;
    cout << ob.graphColoring(graph, m, n) << endl;
  }
  return 0;
}

// } Driver Code Ends
