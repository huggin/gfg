//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  vector<long long> dp;
  long long solve(int k, long long A, long long B) {
    if (dp[k] != -1)
      return dp[k];
    dp[k] = LLONG_MAX;
    if (k > 0)
      dp[k] = min(dp[k], solve(k - 1, A, B) + A);
    // if (k < dp.size())
    // dp[k] = min(dp[k], solve(k+1, A, B)+A);
    if (k % 2 == 0) {
      dp[k] = min(dp[k], solve(k / 2, A, B) + B);
    } else {
      dp[k] = min(dp[k], solve((k + 1) / 2, A, B) + A + B);
    }
    return dp[k];
  }

public:
  long long optimalWalk(long long N, long long A, long long B) {
    // code here
    dp.assign(2 * N, -1);
    dp[0] = 0;
    return solve(N, A, B);
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long N, A, B;
    cin >> N >> A >> B;

    Solution ob;
    cout << ob.optimalWalk(N, A, B) << "\n";
  }
  return 0;
}
// } Driver Code Ends
