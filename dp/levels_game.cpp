//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  int dp[1000][1000][2];

  int solve(int h, int m, int t) {
    if (dp[h][m][t] != -1) return dp[h][m][t];
    if (t == 1 && (h <= 20 && (h <= 5 || m <= 10))) return 0;
    int& ans = dp[h][m][t];
    if (t == 0) {
      ans = solve(h + 3, m + 2, 1) + 1;
    }
    if (h > 20) {
      ans = max(ans, solve(h - 20, m + 5, 0) + 1);
    }
    if (h > 5 && m > 10) {
      ans = max(ans, solve(h - 5, m - 10, 0) + 1);
    }
    return ans;
  }

 public:
  int maxLevel(int h, int m) {
    // code here
    memset(dp, -1, sizeof(dp));
    return solve(h, m, 0);
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  Solution a;
  while (t--) {
    int h, m;
    cin >> h >> m;
    cout << a.maxLevel(h, m) << endl;
  }
  return 0;
}
// } Driver Code Ends
