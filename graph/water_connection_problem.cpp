//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  vector<vector<int>> solve(int n, int p, vector<int> a, vector<int> b,
                            vector<int> d) {
    // code here
    vector<pair<int, int>> adj[n + 1];
    vector<int> start(n + 1);
    for (int i = 0; i < p; ++i) {
      adj[a[i]].emplace_back(b[i], d[i]);
      start[b[i]] = 1;
    }
    vector<vector<int>> ans;
    for (int i = 1; i <= n; ++i) {
      int mi = INT_MAX;
      if (start[i] == 0) {
        int k = i;
        while (adj[k].size() == 1) {
          mi = min(mi, adj[k][0].second);
          k = adj[k][0].first;
        }
        if (mi != INT_MAX) ans.push_back(vector<int>{i, k, mi});
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t, n, p;
  cin >> t;
  while (t--) {
    cin >> n >> p;
    vector<int> a(p), b(p), d(p);
    for (int i = 0; i < p; i++) {
      cin >> a[i] >> b[i] >> d[i];
    }
    Solution obj;
    vector<vector<int>> answer = obj.solve(n, p, a, b, d);
    cout << answer.size() << endl;
    for (auto i : answer) {
      cout << i[0] << " " << i[1] << " " << i[2] << endl;
    }
  }
  return 0;
}
// } Driver Code Ends
