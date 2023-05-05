//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  string s;
  long long dp[1001][1001];

  long long solve(int i, int j) {
    if (i > j)
      return 0;
    if (i == j)
      return 1;

    if (dp[i][j] != -1)
      return dp[i][j];

    if (s[i] != s[j]) {
      dp[i][j] = (solve(i + 1, j) + solve(i, j - 1) - solve(i + 1, j - 1) +
                  1000000007) %
                 1000000007;
    } else {
      dp[i][j] = (solve(i + 1, j) + solve(i, j - 1) + 1) % 1000000007;
    }

    return dp[i][j];
  }

public:
  /*You are required to complete below method */
  long long int countPS(string str) {
    // Your code here
    s = str;
    int n = s.size();
    memset(dp, -1, sizeof(dp));
    long long ans = solve(0, n - 1);
    return ans;
  }
};

//{ Driver Code Starts.
// Driver program
int main() {
  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    Solution ob;
    long long int ans = ob.countPS(str);
    cout << ans << endl;
  }
}
// } Driver Code Ends
