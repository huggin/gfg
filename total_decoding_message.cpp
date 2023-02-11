//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  int CountWays(string str) {
    const int M = 1e9 + 7;
    int n = str.size();
    vector<long long> dp(n + 1);
    dp[0] = 1;
    if (str[0] == '0') return 0;
    dp[1] = 1;
    for (int i = 1; i < n; ++i) {
      if (str[i] == '0') {
        if (str[i - 1] != '1' && str[i - 1] != '2') return 0;
        dp[i + 1] += dp[i - 1];
        dp[i + 1] %= M;
      } else {
        dp[i + 1] += dp[i];
        if (str[i - 1] == '1' ||
            str[i - 1] == '2' && str[i] >= '1' && str[i] <= '6') {
          dp[i + 1] += dp[i - 1];
        }
        dp[i + 1] %= M;
      }
    }
    return dp[n];
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    string str;
    cin >> str;
    Solution obj;
    int ans = obj.CountWays(str);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
