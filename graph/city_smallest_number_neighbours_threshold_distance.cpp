//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

struct Edge {
  int v;
  int w;
  int weight;

  Edge(int v1, int v2, int wt) : v(v1), w(v2), weight(wt) {}
};

class Solution {
public:
  int findCity(int n, int m, vector<vector<int>> &edges,
               int distanceThreshold) {
    vector<vector<int>> g(n, vector<int>(n, -1));
    for (auto &e : edges) {
      g[e[0]][e[1]] = e[2];
      g[e[1]][e[0]] = e[2];
    }
    for (int i = 0; i < n; ++i) {
      g[i][i] = 0;
    }
    for (int k = 0; k < n; ++k) {
      for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
          if (g[i][k] < 0 || g[k][j] < 0)
            continue;
          if (g[i][j] == -1 || g[i][j] > g[i][k] + g[k][j]) {
            g[i][j] = g[i][k] + g[k][j];
          }
        }
      }
    }

    int ans = -1;
    int ok = 0;
    for (int i = 0; i < n; ++i) {
      int t = 0;
      for (int j = 0; j < n; ++j) {
        if (i == j)
          continue;
        if (g[i][j] != -1 && g[i][j] <= distanceThreshold) {
          ++t;
        }
      }
      if (ans == -1 || t <= ok) {
        ans = i;
        ok = t;
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj;
    // n--;
    for (int i = 0; i < m; ++i) {
      vector<int> temp;
      for (int j = 0; j < 3; ++j) {
        int x;
        cin >> x;
        temp.push_back(x);
      }
      adj.push_back(temp);
    }

    int dist;
    cin >> dist;
    Solution obj;
    cout << obj.findCity(n, m, adj, dist) << "\n";
  }
}

// } Driver Code Ends
