//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  int dp[1000][1000];

public:
  int getLongestSubsequence(string A, string B) {
    // code here
    int n = A.size(), m = B.size();
    int ans = 0;

    for (int i = 0; i < n; ++i) {
      if (A[i] == B[0]) {
        dp[i][0] = 1;
        ans = 1;
      } else {
        dp[i][0] = 0;
      }
    }
    for (int j = 0; j < m; ++j) {
      if (A[0] == B[j]) {
        dp[0][j] = 1;
        ans = 1;
      } else {
        dp[0][j] = 0;
      }
    }
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < m; ++j) {
        if (A[i] == B[j]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = dp[i - 1][j];
        }
        ans = max(dp[i][j], ans);
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
    string A, B;

    cin >> A >> B;

    Solution ob;
    cout << ob.getLongestSubsequence(A, B) << endl;
  }
  return 0;
}
// } Driver Code Ends
