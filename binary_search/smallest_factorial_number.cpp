//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  int findNum(int n) {
    // complete the function here
    if (n == 0) return 0;
    int lo = 1;
    int hi = 100000;
    int ans = -1;

    while (lo <= hi) {
      int mi = lo + (hi - lo) / 2;
      int t = 0;
      int m2 = mi;
      while (m2 > 0) {
        t += m2 / 5;
        m2 /= 5;
      }
      if (t < n) {
        lo = mi + 1;
      } else if (t >= n) {
        ans = mi;
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
    int n;
    cin >> n;
    Solution ob;
    cout << ob.findNum(n) << endl;
  }
  return 0;
}
// } Driver Code Ends
