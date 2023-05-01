//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  bool ok(int mid, int N, vector<int> &A, int n) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int k = mid;
      int v = A[i];
      int u = v;
      while (k >= v) {
        ++ans;
        k -= v;
        v += u;
      }
      if (ans >= N)
        return true;
    }
    return false;
  }

public:
  int findMinTime(int N, vector<int> &A, int L) {
    // write your code here
    int lo = 1, hi = INT_MAX;
    int ans = -1;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (ok(mid, N, A, L)) {
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
    int n;
    cin >> n;
    int l;
    cin >> l;
    vector<int> arr(l);
    for (int i = 0; i < l; i++) {
      cin >> arr[i];
    }
    Solution ob;
    int ans = ob.findMinTime(n, arr, l);
    cout << ans << endl;
  }
  return 0;
}

// } Driver Code Ends
