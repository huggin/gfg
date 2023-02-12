//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  long long maxTip(int a[], int b[], int n, int x, int y) {
    // code here
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
      v.emplace_back(a[i] - b[i], i);
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      // cout << v[i].first << v[i].second << endl;
      if (x == 0) {
        ans += b[v[i].second];
        --y;
      } else if (y == 0) {
        ans += a[v[i].second];
        --x;
      } else if (v[i].first <= 0 || n - i > x) {
        ans += b[v[i].second];
        --y;
      } else if (v[i].first > 0) {
        ans += a[v[i].second];
        --x;
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
    int n, x, y;
    cin >> n >> x >> y;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    Solution obj;
    auto ans = obj.maxTip(a, b, n, x, y);
    cout << ans << "\n";
  }
  return 0;
}

// } Driver Code Ends
