//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  long long countWays(int N) {
    // code here
    int mod = 1000000007;
    vector<long long> dp(N + 1);
    dp[0] = 1;
    for (int i = 1; i <= N; ++i) {
      dp[i] = 0;
      if (i >= 4) {
        dp[i] = (dp[i] + dp[i - 4]) % mod;
      }
      if (i >= 3) {
        dp[i] = (dp[i] + dp[i - 3]) % mod;
      }
      dp[i] = (dp[i] + dp[i - 1]) % mod;
    }
    return dp[N];
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;

    cin >> N;

    Solution ob;
    cout << ob.countWays(N) << endl;
  }
  return 0;
}
// } Driver Code Ends
