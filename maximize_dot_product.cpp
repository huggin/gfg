//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  vector<vector<int>> dp;
  int N, M;
  int *a, *b;

  int solve(int i, int j) {
    if (i == N || j == M) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int& ans = dp[i][j];
    ans = solve(i + 1, j + 1) + a[i] * b[j];
    if (N - i > M - j) {
      ans = max(ans, solve(i + 1, j));
    }

    return ans;
  }

 public:
  int maxDotProduct(int n, int m, int A[], int B[]) {
    // Your code goes here
    dp.assign(n, vector<int>(m, -1));
    N = n, M = m;
    a = A, b = B;
    return solve(0, 0);
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;

    int a[n], b[m];

    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < m; i++) cin >> b[i];

    Solution ob;
    cout << ob.maxDotProduct(n, m, a, b) << "\n";
  }
  return 0;
}

// } Driver Code Ends
