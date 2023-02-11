//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  bool enough(int s1, int s2, int n, int t) { return t / s1 + t / s2 >= n; }

 public:
  int minTime(int S1, int S2, int N) {
    // code here
    int lo = 1, hi = 1e9;
    int ans = -1;
    while (lo <= hi) {
      int mi = lo + (hi - lo) / 2;
      bool ok = enough(S1, S2, N, mi);
      if (ok) {
        ans = mi;
        hi = mi - 1;
      } else {
        lo = mi + 1;
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
    int S1, S2, N;
    cin >> S1 >> S2 >> N;

    Solution ob;
    cout << ob.minTime(S1, S2, N) << "\n";
  }
  return 0;
}
// } Driver Code Ends
