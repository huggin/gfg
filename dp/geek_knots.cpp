//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  int knots(int M, int N, int K) {
    // code here
    int mod = 1000000007;
    int ma = M > N ? M : N;
    vector<vector<long long>> dp(ma + 1, vector<long long>(ma + 1, 1));
    for (int i = 2; i <= ma; ++i) {
      dp[i][0] = dp[i][i] = 1;
      for (int j = 1; j < i; ++j) {
        dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
      }
    }

    return (dp[M][K] * dp[N][K]) % mod;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int M, N, K;
    cin >> M >> N >> K;

    Solution ob;
    cout << ob.knots(M, N, K) << "\n";
  }
  return 0;
}
// } Driver Code Ends
