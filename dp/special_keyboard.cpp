//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  using ll = long long;

public:
  long long int optimalKeys(int N) {
    // code here
    vector<ll> dp(77);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;
    for (int i = 5; i <= N; ++i) {
      dp[i] = max({dp[i - 1] + 1, dp[i - 3] * 2, dp[i - 4] * 3, dp[i - 5] * 4});
      // cout << i << ' ' << dp[i] << endl;
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
    cout << ob.optimalKeys(N) << "\n";
  }
  return 0;
}
// } Driver Code Ends
