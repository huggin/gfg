//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  int N, K;
  vector<vector<int>> dp[2];
  const int mod = 1e9 + 7;

  int solve(int i, int k, int d) {
    if (k > K) return 0;
    if (i == N) {
      if (k == K) {
        return 1;
      }
      return 0;
    }
    if (dp[d][i][k] != -1) return dp[d][i][k];
    int& ans = dp[d][i][k];
    if (d == 0) {
      ans = (solve(i + 1, k, 1) + solve(i + 1, k, 0)) % mod;
    } else {
      ans = (solve(i + 1, k + 1, 1) + solve(i + 1, k, 0)) % mod;
    }
    return ans;
  }

 public:
  int countStrings(int n, int k) {
    // code here.
    N = n;
    K = k;
    dp[0].assign(n, vector<int>(k + 1, -1));
    dp[1].assign(n, vector<int>(k + 1, -1));

    return solve(0, 0, 0);
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
    cout << ob.countStrings(n, k) << "\n";
  }
  return 0;
}
// } Driver Code Ends
