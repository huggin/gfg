//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
 public:
  long long int minDaysToEmpty(long long int C, long long int l) {
    // code here
    int lo = 1, hi = C;
    int ans = -1;
    while (lo <= hi) {
      long long mid = lo + (hi - lo) / 2;
      long long drain = mid * (mid + 1) / 2;
      long long fill = mid * (mid - 1) / 2;
      if (mid > l) {
        fill = l * (l + 1) / 2 + (mid - 1 - l) * l;
      }
      // cout << mid << ' ' << fill << ' ' << drain << endl;
      if (fill + C <= drain) {
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
    long long int c, l;
    cin >> c;
    cin >> l;
    Solution ob;
    cout << ob.minDaysToEmpty(c, l) << endl;
  }
  return 0;
}

// } Driver Code Ends
