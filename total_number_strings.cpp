//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  int no_ofString(int n) {
    // Code here
    const int M = 1e9 + 7;
    long long ans = 1;                        // all a;
    ans += n;                                 // one b, all a;
    ans += n;                                 // one c, all a;
    ans = (ans + 1LL * n * (n - 1) / 2) % M;  // 2 c, all a;
    ans = (ans + 1LL * n * (n - 1) % M) % M;  // 1 b, 1 c, all a;
    ans = (ans + (1LL * n * (n - 1) / 2) % M * (n - 2) % M) %
          M;  // 1b, 2c, all a;
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    Solution ob;
    int ans = ob.no_ofString(n);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
