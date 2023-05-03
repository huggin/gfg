//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  long long binPow(int base, int e, int mod) {
    if (e == 0)
      return 1;
    if (e == 1)
      return base;
    long long ans = binPow(base, e / 2, mod);
    ans = ans * ans % mod;
    if (e % 2 == 1) {
      ans = ans * base % mod;
    }
    return ans;
  }

  vector<vector<long long>> dp;
  int mod = 1e9 + 7;
  int v;

  long long solve(int n, int k) {
    if (n == 0)
      return 1;

    if (dp[n][k] != -1) {
      return dp[n][k];
    }
    if (n <= k) {
      return dp[n][k] = binPow(26, n, mod);
    }
    if (k == 0) {
      return dp[n][k] = 21 * solve(n - 1, v);
    }

    long long &ans = dp[n][k];
    ans = 21 * solve(n - 1, v) % mod;
    ans = (ans + 5 * solve(n - 1, k - 1)) % mod;
    // cout << n << ' ' << k << ' ' << ans << endl;
    return ans;
  }

public:
  int kvowelwords(int N, int K) {
    // Write Your Code here
    v = K;
    dp.resize(N + 1);
    for (int i = 1; i < N + 1; ++i) {
      dp[i].resize(K + 1, -1);
    }
    return solve(N, K);
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    int K;
    cin >> N >> K;

    Solution ob;
    int ans = ob.kvowelwords(N, K);
    cout << ans << endl;
  }
  return 0;
}
// } Driver Code Ends
