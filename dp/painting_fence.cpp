//{ Driver Code Starts
#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  long long countWays(int n, int k) {
    // code here
    if (n == 1) return k;
    const int mod = 1000000007;
    vector<long long> dp(n + 1);
    dp[0] = 1;
    dp[1] = k;
    dp[2] = dp[0] * k + dp[1] * (k - 1);
    for (int i = 3; i <= n; ++i) {
      dp[i] = (k - 1) * (dp[i - 1] + dp[i - 2]) % mod;
    }
    return dp[n];
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    Solution ob;
    cout << ob.countWays(n, k) << endl;
  }
  return 0;
}
// } Driver Code Ends
