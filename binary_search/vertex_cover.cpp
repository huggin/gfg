//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  int N;

  long long next(long long n, int k) {
    long long t = n;
    int c1 = 0;
    int c0 = 0;
    while (((t & 1) == 0) && (t != 0)) {
      c0++;
      t >>= 1;
    }
    while ((t & 1) == 1) {
      c1++;
      t >>= 1;
    }
    int C = c0 + c1;
    n |= (1 << C);
    n &= ~((1 << C) - 1);
    n |= (1 << (c1 - 1)) - 1;

    return n;
  }
  bool ok(int k, vector<pair<int, int>>& edge) {
    if (k == N) return true;
    long long mask = (1 << k) - 1;
    long long limit = 1 << N;
    int m = edge.size();
    while (mask < limit) {
      // cout << "mask = " << mask << endl;
      int num = 0;
      for (auto e : edge) {
        if ((mask & (1 << (e.first - 1))) || (mask & (1 << (e.second - 1))))
          ++num;
      }
      if (num == m) {
        // cout << "mask = " << mask << endl;
        return true;
      }
      mask = next(mask, k);
    }
    return false;
  }

 public:
  int vertexCover(int n, vector<pair<int, int>>& edges) {
    // code here
    N = n;
    int lo = 1, hi = n;
    int ans = -1;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (ok(mid, edges)) {
        ans = mid;
        hi = mid - 1;
      } else {
        lo = mid + 1;
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
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      edges.push_back({a, b});
    }
    Solution s;
    cout << s.vertexCover(n, edges) << endl;
  }
  return 0;
}
// } Driver Code Ends
