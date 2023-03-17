//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  int countOfDistinctNo(string str) {
    // Code here
    vector<int> cnt(16);
    for (char c : str) {
      if (c >= '0' && c <= '9')
        cnt[c - '0']++;
      else
        cnt[c - 'A' + 10]++;
    }

    const int M = 1e9 + 7;

    int n = str.size();
    vector<vector<int>> c(n + 1, vector<int>(n + 1, 1));
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j < i; ++j) {
        c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % M;
      }
    }

    vector<long long> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i < 16; ++i) {
      int f = cnt[i];
      if (f == 0) continue;
      for (int j = n; j >= 0; --j) {
        for (int k = 1; k <= f; ++k) {
          if (j - k >= 0) dp[j] = (dp[j] + dp[j - k] * c[j][k]) % M;
        }
      }
    }

    int f = cnt[0];
    for (int j = n; j >= 0; --j) {
      for (int k = 1; k <= f; ++k) {
        if (j - k >= 0) {
          dp[j] = (dp[j] + dp[j - k] * (c[j - 1][k])) % M;
        }
      }
    }

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
      ans = (ans + dp[i]) % M;
    }
    if (f > 1) ans -= (f - 1);
    return ans;
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
    int ans = obj.countOfDistinctNo(str);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
