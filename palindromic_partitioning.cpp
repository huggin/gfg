//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  char dp[500][500];
  int n;
  int dp2[500];

  int solve(int k) {
    if (k == n) return 0;
    if (dp[k][n - 1] == 1) return 0;
    if (dp2[k] != -1) return dp2[k];
    int& ans = dp2[k];
    ans = n;
    for (int i = k; i < n; ++i) {
      if (dp[k][i] == 1) {
        ans = min(ans, 1 + solve(i + 1));
      }
    }
    return ans;
  }

 public:
  int palindromicPartition(string str) {
    // code here
    memset(dp, 0, sizeof(dp));
    n = str.size();
    for (int i = 0; i < n; ++i) dp[i][i] = 1;
    for (int i = 1; i < n; ++i) {
      if (str[i - 1] == str[i]) {
        dp[i - 1][i] = 1;
      }
    }
    for (int k = 2; k < n; ++k) {
      for (int i = 0; i + k < n; ++i) {
        if (str[i] == str[i + k] && dp[i + 1][i + k - 1] == 1) {
          dp[i][i + k] = 1;
        }
      }
    }
    memset(dp2, -1, sizeof(dp2));
    return solve(0);
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;

    Solution ob;
    cout << ob.palindromicPartition(str) << "\n";
  }
  return 0;
}
// } Driver Code Ends
