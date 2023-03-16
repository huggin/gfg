//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  string longestPalin(string S) {
    // code here
    string ans;
    int len = INT_MIN;
    vector<vector<int>> dp(S.size(), vector<int>(S.size()));
    for (int i = 0; i < S.size(); ++i) dp[i][i] = 1;
    for (int j = 1; j < S.size(); ++j) {
      if (S[j] == S[j - 1]) {
        dp[j - 1][j] = 1;
      }
    }
    for (int j = 2; j < S.size(); ++j) {
      for (int i = 0; i + j < S.size(); ++i) {
        if (dp[i + 1][i + j - 1] == 1 && S[i] == S[i + j]) {
          dp[i][i + j] = 1;
        }
      }
    }
    for (int i = 0; i < S.size(); ++i) {
      for (int j = i; j < S.size(); ++j) {
        if (dp[i][j] == 1) {
          // cout << i << ' ' << j << endl;
          if (j - i + 1 > len) {
            len = j - i + 1;
            ans = S.substr(i, j - i + 1);
          }
        }
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    string S;
    cin >> S;

    Solution ob;
    cout << ob.longestPalin(S) << endl;
  }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
