//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  int countDivisibleSubseq(string s, int N) {
    // Your code goes here
    int mod = 1000000007;
    int n = s.size();
    vector<vector<long long>> dp(n + 1, vector<long long>(N + 1));
    dp[0][(s[0] - '0') % N] = 1;
    for (int i = 1; i < n; ++i) {
      int t = s[i] - '0';
      dp[i][(s[i] - '0') % N] = 1;
      for (int j = 0; j < N; ++j) {
        dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
        dp[i][(j * 10 + t) % N] += dp[i - 1][j];
        dp[i][(j * 10 + t) % N] % mod;
      }
    }

    return dp[n - 1][0] % mod;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;

    int n;
    cin >> n;

    Solution ob;
    cout << ob.countDivisibleSubseq(s, n) << "\n";
  }
  return 0;
}

// } Driver Code Ends
