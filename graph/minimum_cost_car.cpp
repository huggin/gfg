//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  int minimumCost(int n, vector<vector<int>> &cars, int src, int dst, int k) {
    if (src == dst) return 0;
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < cars.size(); ++i) {
      g[cars[i][0]][cars[i][1]] = cars[i][2];
    }
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<tuple<int, int, int>>>
        q;
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    q.emplace(0, 0, src);

    while (!q.empty()) {
      auto c = q.top();
      q.pop();
      // cout << get<0>(c) << ' ' << get<1>(c) << ' ' << get<2>(c) << endl;
      if (get<1>(c) == k + 1) continue;
      for (int i = 0; i < n; ++i) {
        if (g[get<2>(c)][i] == 0) continue;
        if (dist[i] > dist[get<2>(c)] + g[get<2>(c)][i]) {
          dist[i] = dist[get<2>(c)] + g[get<2>(c)][i];
          q.emplace(dist[i], get<1>(c) + 1, i);
        }
      }
    }

    if (dist[dst] == INT_MAX) return -1;
    return dist[dst];
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, src, dst, k;
    cin >> n >> src >> dst >> k >> m;
    vector<vector<int>> cars(m, vector<int>(3));
    for (auto &j : cars) cin >> j[0] >> j[1] >> j[2];
    Solution s;
    cout << s.minimumCost(n, cars, src, dst, k) << endl;
  }
  return 0;
}
// } Driver Code Ends
