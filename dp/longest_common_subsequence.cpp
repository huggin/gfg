//{ Driver Code Starts
#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution {
public:
  // Function to find the length of longest common subsequence in two strings.
  int lcs(int x, int y, string s1, string s2) {
    // your code here
    int dp[1001][1001] = {0};
    dp[0][0] = s1[0] == s2[0];
    for (int i = 1; i < x; ++i) {
      if (s1[i] == s2[0] || dp[i - 1][0]) {
        dp[i][0] = 1;
      }
    }
    for (int i = 1; i < y; ++i) {
      if (s1[0] == s2[i] || dp[0][i - 1]) {
        dp[0][i] = 1;
      }
    }
    for (int i = 1; i < x; ++i) {
      for (int j = 1; j < y; ++j) {
        if (s1[i] == s2[j]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        }
        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        dp[i][j] = max(dp[i][j], dp[i][j - 1]);
      }
    }
    return dp[x - 1][y - 1];
  }
};

//{ Driver Code Starts.
int main() {
  int t, n, k, x, y;
  cin >> t;
  while (t--) {
    cin >> x >> y; // Take size of both the strings as input
    string s1, s2;
    cin >> s1 >> s2; // Take both the string as input
    Solution ob;
    cout << ob.lcs(x, y, s1, s2) << endl;
  }
  return 0;
}

// } Driver Code Ends
