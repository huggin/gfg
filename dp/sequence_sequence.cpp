//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  vector<vector<int>> dp;

  int solve(int m, int n) {
    if (n == 0)
      return 1;
    if (m < n)
      return 0;
    if (dp[m][n] != -1)
      return dp[m][n];
    return dp[m][n] = solve(m - 1, n) + solve(m / 2, n - 1);
  }

public:
  int numberSequence(int m, int n) {
    // code here
    dp.assign(m + 1, vector<int>(n + 1, -1));
    return solve(m, n);
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
    cout << ob.numberSequence(m, n) << endl;
  }
  return 0;
}
// } Driver Code Ends
