//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  vector<vector<long long>> dp;
  int n, m;
  int mod = 1000000007;

  long long solve(int k, int d) {
    if (k == n - 1) return 1;
    if (dp[k][d] != -1) return dp[k][d];
    long long& ans = dp[k][d];
    ans = 0;
    for (int i = 1; i <= m; ++i) {
      if (d % i == 0 || i % d == 0) {
        ans = (ans + solve(k + 1, i)) % mod;
      }
    }
    return ans;
  }

 public:
  long long count(long long N, long long M) {
    // code here
    dp.assign(N + 1, vector<long long>(M + 1, -1));
    n = N, m = M;
    long long ans = 0;
    for (int i = 1; i <= M; ++i) {
      ans = (ans + solve(0, i)) % mod;
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long N, M;
    cin >> N >> M;
    Solution ob;
    cout << ob.count(N, M) << endl;
  }
  return 0;
}
// } Driver Code Ends
