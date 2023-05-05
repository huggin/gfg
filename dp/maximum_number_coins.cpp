//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  vector<vector<int>> dp;

  int solve(const vector<int> &b, int i, int j) {
    if (i > j)
      return 0;
    if (i == j)
      return b[i] * b[i - 1] * b[j + 1];
    if (dp[i][j] != -1)
      return dp[i][j];
    int &ans = dp[i][j];
    ans = 0;
    for (int k = i; k <= j; ++k) {
      ans = max(ans, solve(b, i, k - 1) + solve(b, k + 1, j) +
                         b[k] * b[i - 1] * b[j + 1]);
    }
    return ans;
  }

public:
  int maxCoins(int N, vector<int> &a) {
    // write your code here
    vector<int> b(N + 2, 1);
    for (int i = 0; i < N; ++i)
      b[i + 1] = a[i];

    dp.assign(N + 2, vector<int>(N + 2, -1));
    return solve(b, 1, N);
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    Solution S;
    cout << S.maxCoins(n, a) << endl;
  }
  return 0;
}
// } Driver Code Ends
