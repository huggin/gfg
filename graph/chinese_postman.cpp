//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  int chinesePostmanProblem(std::vector<std::vector<int>> &e, int n) {
    if (e.empty()) {
      return 0;
    }
    int tot = 0;
    const int oo = 1000;
    std::vector<std::vector<int>> g(n, std::vector<int>(n, oo));
    for (auto &edge : e) {
      int u = edge[0] - 1;
      int v = edge[1] - 1;
      int w = edge[2];
      g[u][v] = w;
      g[v][u] = w;
      tot += w;
    }

    for (int i = 0; i < n; ++i) {
      g[i][i] = 0;
    }

    std::vector<int> odd;
    for (int i = 0; i < n; ++i) {
      int cnt = 0;
      for (int j = 0; j < n; ++j) {
        if (g[i][j] > 0 && g[i][j] != oo) {
          cnt++;
        }
      }
      if (cnt % 2 == 1) {
        odd.push_back(i);
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
          g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);
        }
      }
    }

    int m = odd.size();
    if (m == 0) {
      return tot;
    }

    int ans = oo;
    function<void(int)> dfs = [&](int i) {
      if (i == m) {
        int dist = 0;
        for (int j = 1; j < m; j += 2) {
          dist += g[odd[j - 1]][odd[j]];
        }
        ans = std::min(ans, dist);
        return;
      }
      for (int j = i; j < m; ++j) {
        std::swap(odd[i], odd[j]);
        dfs(i + 1);
        std::swap(odd[i], odd[j]);
      }
    };

    dfs(0);
    if (ans == oo) {
      return -1;
    }

    return ans + tot;
  }
};

//{ Driver Code Starts.
int main() {
  int t = 1, testcases = 1;
  cin >> t;
  while (t >= testcases) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(3));
    for (auto &j : edges) {
      for (auto &i : j)
        cin >> i;
    }
    Solution s;
    cout << s.chinesePostmanProblem(edges, n) << endl;
    testcases++;
  }
  return 0;
}
// } Driver Code Ends
