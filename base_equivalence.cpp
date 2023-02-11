//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  int ok(int n, int b) {
    int ans = 0;
    while (n > 0) {
      ++ans;
      n /= b;
    }
    return ans;
  }

 public:
  string baseEquiv(int n, int m) {
    // code here
    int lo = 2, hi = 32;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      int d = ok(n, mid);
      if (d == m)
        return "Yes";
      else if (d > m)
        lo = mid + 1;
      else
        hi = mid - 1;
    }
    return "No";
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    Solution ob;
    cout << ob.baseEquiv(n, m) << endl;
  }
  return 0;
}

// } Driver Code Ends
