//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  int TotalWays(int N) {
    // Code here
    int const mod = 1000000007;
    vector<long long> dp(N + 1);
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i <= N; ++i) {
      dp[i] = (dp[i - 2] + dp[i - 1]) % mod;
    }
    return (dp[N]) * (dp[N]) % mod;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int N;
    cin >> N;
    Solution ob;
    int ans = ob.TotalWays(N);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code End
