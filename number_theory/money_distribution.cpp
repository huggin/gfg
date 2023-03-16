//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  long long inv(long long a, int m) {
    long long b = m - 2;
    long long ans = 1;
    while (b) {
      if (b & 1) ans = ans * a % m;
      a = a * a % m;
      b >>= 1;
    }

    return ans;
  }

 public:
  int totalWays(int N, int K) {
    // Code here.
    if (K > N) return 0;
    const int M = 1e9 + 7;
    vector<long long> dp(N + 1);
    dp[0] = 1;
    for (int i = 1; i <= N; ++i) {
      dp[i] = dp[i - 1] * i % M;
    }

    return dp[N - 1] * inv(dp[K - 1] * dp[N - K] % M, M) % M;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    Solution ob;
    int ans = ob.totalWays(n, k);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
