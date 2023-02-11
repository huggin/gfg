//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  int n;
  string s;
  int dp[200][200][2];

  int solve(int i, int j, int v) {
    if (dp[i][j][v] != -1) return dp[i][j][v];
    if (i == j) {
      if (s[i] == 'T') {
        if (v == 1) return 1;
        return 0;
      } else {
        if (v == 1) return 0;
        return 1;
      }
    }
    int &ans = dp[i][j][v];

    ans = 0;
    if (v == 1) {
      for (int k = i + 1; k < j; k += 2) {
        if (s[k] == '|') {
          ans += solve(i, k - 1, 1) * solve(k + 1, j, 0) +
                 solve(i, k - 1, 1) * solve(k + 1, j, 1) +
                 solve(i, k - 1, 0) * solve(k + 1, j, 1);
        }
        if (s[k] == '&') {
          ans += solve(i, k - 1, 1) * solve(k + 1, j, 1);
        }
        if (s[k] == '^') {
          ans += solve(i, k - 1, 1) * solve(k + 1, j, 0) +
                 solve(i, k - 1, 0) * solve(k + 1, j, 1);
        }
      }
    } else {
      for (int k = i + 1; k < j; k += 2) {
        if (s[k] == '|') {
          ans += solve(i, k - 1, 0) * solve(k + 1, j, 0);
        }
        if (s[k] == '&') {
          ans += solve(i, k - 1, 0) * solve(k + 1, j, 1) +
                 +solve(i, k - 1, 1) * solve(k + 1, j, 0) +
                 solve(i, k - 1, 0) * solve(k + 1, j, 0);
        }
        if (s[k] == '^') {
          ans += solve(i, k - 1, 1) * solve(k + 1, j, 1) +
                 solve(i, k - 1, 0) * solve(k + 1, j, 0);
        }
      }
    }
    // cout << i << ' ' << j << ' ' << v << ' ' << ans << endl;
    return ans = ans % 1003;
  }

 public:
  int countWays(int N, string S) {
    // code here
    n = N;
    s = S;
    memset(dp, -1, sizeof(dp));
    return solve(0, N - 1, 1);
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    string S;
    cin >> S;

    Solution ob;
    cout << ob.countWays(N, S) << "\n";
  }
  return 0;
}
// } Driver Code Ends
