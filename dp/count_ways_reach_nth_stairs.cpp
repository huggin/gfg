//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  // Function to count number of ways to reach the nth stair.
  int countWays(int n) {
    // your code here
    const int M = 1e9 + 7;
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
      if (i >= 1) {
        dp[i] += dp[i - 1];
        dp[i] %= M;
      }
      if (i >= 2) {
        dp[i] += dp[i - 2];
        dp[i] %= M;
      }
    }
    return dp[n];
  }
};

//{ Driver Code Starts.
int main() {
  // taking total testcases
  int t;
  cin >> t;
  while (t--) {
    // taking stair count
    int m;
    cin >> m;
    Solution ob;
    cout << ob.countWays(m)
         << endl; // Print the output from our pre computed array
  }
  return 0;
}

// } Driver Code Ends
