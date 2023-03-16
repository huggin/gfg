//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

struct cmp {
  bool operator()(pair<int, int> l, pair<int, int> r) {
    if (l.first == r.first) {
      if (l.first < 0 && r.first < 0) {
        return l.second < r.second;
      } else {
        return l.second > r.second;
      }
    }
    return l.first < r.first;
  }
};

class Solution {
 public:
  vector<vector<int>> minCashFlow(vector<vector<int>> &t, int n) {
    // code here
    if (n == 0) return t;
    if (n == 1) {
      t[0][0] = 0;
      return t;
    }
    set<pair<int, int>, cmp> S;
    vector<int> net(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        net[i] += t[i][j];
        net[j] -= t[i][j];
      }
    }
    for (int i = 0; i < n; ++i) {
      S.insert({net[i], i});
    }
    vector<vector<int>> ans(n, vector<int>(n));
    while (true) {
      auto a = S.begin();
      int a1 = a->first;
      int a2 = a->second;
      S.erase(a);
      auto b = S.end();
      --b;
      int b1 = b->first;
      int b2 = b->second;
      S.erase(b);

      if (a1 == 0 && b1 == 0) break;
      int diff = min(-a1, b1);
      ans[b2][a2] += diff;
      S.insert({a1 + diff, a2});
      S.insert({b1 - diff, b2});
    }

    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) cin >> g[i][j];
    }
    Solution s;
    vector<vector<int>> r = s.minCashFlow(g, n);
    for (auto j : r) {
      for (auto i : j) cout << i << " ";
      cout << endl;
    }
    // cout<<endl;
  }
  return 0;
}
// } Driver Code Ends
