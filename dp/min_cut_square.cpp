//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  vector<vector<int>> dp;
  int solve(int i, int j) {
    if (i == 0 || j == 0)
      return 0;
    if (i % j == 0)
      return i / j;
    if (j % i == 0)
      return j / i;
    if (dp[i][j] != -1)
      return dp[i][j];
    int &ans = dp[i][j];
    ans = 10000;
    for (int k = 1; k <= min(i, j); ++k) {
      ans = min(ans, solve(k, j) + solve(i - k, j));
      ans = min(ans, solve(i, k) + solve(i, j - k));
    }
    dp[j][i] = ans;
    return ans;
  }

public:
  int minCut(int M, int N) {
    // Your code goes here
    dp.assign(M + N + 1, vector<int>(M + N + 1, -1));
    return solve(M, N);
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int m, n;
    cin >> m >> n;

    Solution ob;
    cout << ob.minCut(m, n) << "\n";
  }
  return 0;
}

// } Driver Code Ends
