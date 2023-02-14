//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  int countWays(int m, int n, int p, int arr[]) {
    // code here
    int ball = m - p;
    int need = accumulate(arr, arr + n, 0);
    if (ball < need) return -1;
    int more = ball - need;
    vector<vector<int>> dp(n + more + 1, vector<int>(n + more + 1, 1));
    for (int i = 2; i < n + more; ++i) {
      for (int j = 1; j < i; ++j) {
        dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 1000000007;
      }
    }
    return dp[n + more - 1][n - 1];
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int m, n, p;
    cin >> m >> n >> p;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    Solution ob;
    cout << ob.countWays(m, n, p, arr) << endl;
  }
  return 0;
}
// } Driver Code Ends
