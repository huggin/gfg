//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Position this line where user code will be pasted.

class Solution {
  vector<vector<int>> dp;
  int n;
  int solve(int c[], int k, int w) {
    if (k == n) {
      if (w == 0)
        return 0;
      else
        return 100000000;
    }
    if (dp[k][w] != -1) return dp[k][w];
    int& ans = dp[k][w];
    ans = solve(c, k + 1, w);
    if (w >= k + 1 && c[k] > 0) {
      ans = min(ans, c[k] + solve(c, k, w - (k + 1)));
    }
    // cout << k << ' ' << w << ' ' << ans << endl;
    return ans;
  }

 public:
  int minimumCost(int cost[], int N, int W) {
    // Your code goes here
    dp.assign(N, vector<int>(W + 1, -1));
    n = N;
    int ans = solve(cost, 0, W);
    if (ans >= 10000000) return -1;
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, w;
    cin >> n >> w;

    int a[n];

    for (int i = 0; i < n; i++) cin >> a[i];

    Solution ob;
    cout << ob.minimumCost(a, n, w) << "\n";
  }
  return 0;
}
// } Driver Code Ends
