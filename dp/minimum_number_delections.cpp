//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << minDeletions(s, n) << endl;
  }
  return 0;
}
// } Driver Code Ends

int minDeletions(string str, int n) {
  // complete the function here
  vector<vector<int>> dp(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    dp[i][i] = 0;
  }
  for (int i = 1; i < n; ++i) {
    if (str[i - 1] != str[i]) {
      dp[i - 1][i] = 1;
    }
  }
  for (int i = 2; i < n; ++i) {
    for (int j = 0; j + i < n; ++j) {
      if (str[j + i] == str[j]) {
        dp[j][j + i] = dp[j + 1][j + i - 1];
      } else {
        dp[j][i + j] = 1 + min(dp[j + 1][j + i], dp[j][j + i - 1]);
      }
    }
  }
  return dp[0][n - 1];
}
