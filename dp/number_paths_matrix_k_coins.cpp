//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  long long dp[100][100][100];
  vector<vector<int>> a;
  int N;

  long long solve(int i, int j, int k) {
    if (i == N - 1 && j == N - 1) {
      // cout << i << ' ' << j << ' ' << k << ' ' << 1 << endl;
      if (a[i][j] == k)
        return 1;
      else
        return 0;
    }

    if (dp[i][j][k] != -1)
      return dp[i][j][k];
    long long &ans = dp[i][j][k];
    ans = 0;
    if (j + 1 < N) {
      ans += solve(i, j + 1, k - a[i][j]);
    }
    if (i + 1 < N) {
      ans += solve(i + 1, j, k - a[i][j]);
    }
    // cout << i << ' ' << j << ' ' << k << ' ' << ans << endl;
    return ans;
  }

public:
  long long numberOfPath(int n, int k, vector<vector<int>> arr) {
    // Code Here
    a = arr;
    N = n;
    memset(dp, -1, sizeof(dp));
    return solve(0, 0, k);
  }
};

//{ Driver Code Starts.

int main() {
  Solution obj;
  int i, j, k, l, m, n, t;
  cin >> t;
  while (t--) {
    cin >> k >> n;
    vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
        cin >> v[i][j];
    cout << obj.numberOfPath(n, k, v) << endl;
  }
}
// } Driver Code Ends
