//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  bool ok(const vector<int>& s, int n, int k, int dist) {
    int u = 1;
    int prev = s[0];
    for (int i = 1; i < n; ++i) {
      if (s[i] - prev >= dist) {
        ++u;
        prev = s[i];
      }
    }
    return u >= k;
  }

 public:
  int solve(int n, int k, vector<int>& stalls) {
    // Write your code here
    int lo = 0, hi = 1e9;
    int ans = -1;
    sort(stalls.begin(), stalls.end());

    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (ok(stalls, n, k, mid)) {
        ans = mid;
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t = 1;
  cin >> t;

  // freopen ("output_gfg.txt", "w", stdout);

  while (t--) {
    // Input

    int n, k;
    cin >> n >> k;

    vector<int> stalls(n);
    for (int i = 0; i < n; i++) {
      cin >> stalls[i];
    }
    // char ch;
    // cin >> ch;

    Solution obj;
    cout << obj.solve(n, k, stalls) << endl;

    // cout << "~\n";
  }
  // fclose(stdout);

  return 0;
}
// } Driver Code Ends
