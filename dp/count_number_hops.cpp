//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  // Function to count the number of ways in which frog can reach the top.
  long long countWays(int n) {
    // your code here
    const int M = 1e9 + 7;
    vector<long long> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
      dp[i] = (dp[i - 2] + dp[i - 1]) % M;
      if (i - 3 >= 0)
        dp[i] = (dp[i] + dp[i - 3]) % M;
    }
    return dp[n];
  }
};

//{ Driver Code Starts.
int main() {
  // taking testcases
  int t;
  cin >> t;

  while (t--) {
    // taking number of steps in stair
    int n;
    cin >> n;
    Solution ob;
    // calling function countWays()
    cout << ob.countWays(n) << endl;
  }

  return 0;
}

// } Driver Code Ends
