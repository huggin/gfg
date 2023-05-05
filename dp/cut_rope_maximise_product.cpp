//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
public:
  long long maxProduct(int n) {
    // code here
    if (n == 1)
      return 0;
    vector<long long> dp(n + 1);
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 2; i <= n; ++i) {
      dp[i] = 0;
      for (int j = 1; j < i; ++j) {
        dp[i] = max(dp[i], max((long long)j, dp[j]) *
                               max((long long)i - j, dp[i - j]));
      }
    }
    return dp[n];
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    Solution ob;
    auto ans = ob.maxProduct(n);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
