//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  int minHours(int N) {
    // code here
    if (N % 2 == 1 || N < 10) return -1;
    vector<int> dp(N + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= N; ++i) {
      dp[i] = 1000000;
      if (i - 12 >= 0 && dp[i - 12] != -1) {
        dp[i] = min(dp[i], dp[i - 12] + 1);
      }
      if (i - 10 >= 0 && dp[i - 10] != -1) {
        dp[i] = min(dp[i], dp[i - 10] + 1);
      }
      // cout << i << ' ' << dp[i] << endl;
      if (dp[i] == 1000000) dp[i] = -1;
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
    cout << ob.minHours(N) << "\n";
  }
  return 0;
}
// } Driver Code Ends
