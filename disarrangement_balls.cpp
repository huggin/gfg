//{ Driver Code Starts
// Initial function Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  long int disarrange(int N) {
    // code here
    const int MOD = 1000000007;
    long long dp[N + 1];
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 2;
    for (int i = 4; i <= N; ++i) {
      dp[i] = (dp[i - 1] + dp[i - 2]) * (i - 1) % MOD;
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
    cout << ob.disarrange(N) << "\n";
  }
  return 0;
}
// } Driver Code End
