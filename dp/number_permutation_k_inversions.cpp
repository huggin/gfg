//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  vector<vector<long long>> dp;
  const int M = 1e9 + 7;
  long long solve(int n, int k) {
    if (k == 0) return 1;
    if (n <= 1) return 0;
    // if (k > n && k > n * (n-1) / 2) return 0;

    if (dp[n][k] != -1) return dp[n][k];
    dp[n][k] = 0;
    for (int i = 0; i <= k; ++i) {
      if (k <= n - 1 + i) {
        dp[n][k] = (dp[n][k] + solve(n - 1, i)) % M;
      }
    }
    // cout << n << ' ' << k << ' ' << dp[n][k] << endl;
    return dp[n][k];
  }

 public:
  int numberOfPermWithKInversion(int N, int K) {
    // Your code goes here
    dp.assign(N + 1, vector<long long>(K + 1, -1));

    return solve(N, K);
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
    cout << ob.numberOfPermWithKInversion(n, k) << "\n";
  }
  return 0;
}

// } Driver Code Ends
