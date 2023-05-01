//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  int lessthan(int k, int m, int n) {
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
      if (k >= i * n)
        ans += n;
      else
        ans += k / i;
    }
    return ans;
  }

public:
  int KthSmallest(int m, int n, int k) {
    // Write your code here
    int lo = 1, hi = m * n;
    int ans = -1;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      int num = lessthan(mid, m, n);
      if (num >= k) {
        ans = mid;
        hi = mid - 1;
      } else if (num <= k) {
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
    int m, n, k;
    cin >> m >> n >> k;
    Solution ob;
    int ans = ob.KthSmallest(m, n, k);
    cout << ans << endl;
  }
  return 0;
}

// } Driver Code Ends
