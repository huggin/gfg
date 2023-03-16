//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  vector<vector<int>> dp;
  int n;

  int solve(const string& s, int i, int j) {
    if (i >= j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (s[i] == s[j]) {
      dp[i][j] = solve(s, i + 1, j - 1);
    } else {
      dp[i][j] = 1 + min(solve(s, i + 1, j), solve(s, i, j - 1));
    }
    return dp[i][j];
  }

 public:
  int isPossiblePalindrome(string s, int K) {
    // Your code goes here
    n = s.size();
    dp.assign(n, vector<int>(n, -1));
    int ans = solve(s, 0, n - 1);
    return K >= ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;

    int k;
    cin >> k;

    Solution ob;
    cout << ob.isPossiblePalindrome(s, k) << "\n";
  }
  return 0;
}
// } Driver Code Ends
