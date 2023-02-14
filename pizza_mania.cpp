//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  int dp[501];
  int s, m, l, cs, cm, cl;

  int solve(int x) {
    if (x <= 0) return 0;
    if (dp[x] != -1) return dp[x];
    dp[x] = cs + solve(x - s);
    dp[x] = min(dp[x], cm + solve(x - m));
    dp[x] = min(dp[x], cl + solve(x - l));
    return dp[x];
  }

 public:
  int getPizza(int X, int S, int M, int L, int CS, int CM, int CL) {
    // code here
    memset(dp, -1, sizeof(dp));
    s = S, m = M, l = L, cs = CS, cm = CM, cl = CL;
    return solve(X);
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int X, S, M, L, CS, CM, CL;

    cin >> X >> S >> M >> L >> CS >> CM >> CL;

    Solution ob;
    cout << ob.getPizza(X, S, M, L, CS, CM, CL) << endl;
  }
  return 0;
}
// } Driver Code Ends
