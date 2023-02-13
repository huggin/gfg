//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool is_k_palin(string s, int k);

int main() {
  // your code goes here
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int k;
    cin >> k;

    cout << is_k_palin(s, k) << endl;
  }
  return 0;
}
// } Driver Code Ends

/*You are required to complete this function*/
bool is_k_palin(string s, int k) {
  // Your code here
  int n = s.size();
  int dp[n][n] = {0};
  for (int i = 0; i < n; ++i) {
    dp[i][i] = 0;
  }
  for (int i = 1; i < n; ++i) {
    if (s[i - 1] == s[i]) {
      dp[i - 1][i] = 0;
    } else {
      dp[i - 1][i] = 1;
    }
  }
  for (int j = 2; j < n; ++j) {
    for (int i = 0; i + j < n; ++i) {
      if (s[i] == s[i + j])
        dp[i][i + j] = dp[i + 1][i + j - 1];
      else {
        dp[i][i + j] = min(dp[i + 1][i + j], dp[i][i + j - 1]) + 1;
      }
    }
  }
  return dp[0][n - 1] <= k;
}
