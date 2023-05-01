//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  bool ok(const vector<int> &a, int k, int w, int mi, int n) {
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
      if (i > 0)
        b[i] += b[i - 1];
      if (a[i] + b[i] < mi) {
        k -= mi - a[i] - b[i];
        if (k < 0)
          return false;
        if (i + w < n) {
          b[i + w] -= mi - a[i] - b[i];
        }
        b[i] += mi - a[i] - b[i];
      }
    }
    return true;
  }

public:
  long long int maximizeMinHeight(int n, int k, int w, vector<int> &a) {
    // code here
    long long lo = *min_element(a.begin(), a.end());
    long long hi = lo + k;

    long long ans = -1;
    while (lo <= hi) {
      int mi = lo + (hi - lo) / 2;
      if (ok(a, k, w, mi, n)) {
        ans = mi;
        lo = mi + 1;
      } else {
        hi = mi - 1;
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
    int n, k, w;
    cin >> n >> k >> w;
    vector<int> a(n);
    for (auto &j : a)
      cin >> j;
    Solution s;
    cout << s.maximizeMinHeight(n, k, w, a) << endl;
  }
  return 0;
}
// } Driver Code Ends
