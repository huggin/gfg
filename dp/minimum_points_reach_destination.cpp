//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  int minPoints(vector<vector<int>> points, int M, int N) {
    // Your code goes here
    vector<vector<int>> dp(M, vector<int>(N));
    dp[M - 1][N - 1] = points[M - 1][N - 1] >= 0 ? 0 : points[M - 1][N - 1];
    for (int i = M - 2; i >= 0; --i) {
      int t = dp[i + 1][N - 1] + points[i][N - 1];
      dp[i][N - 1] = t >= 0 ? 0 : t;
    }
    for (int j = N - 2; j >= 0; --j) {
      int t = dp[M - 1][j + 1] + points[M - 1][j];
      dp[M - 1][j] = t >= 0 ? 0 : t;
    }
    for (int i = M - 2; i >= 0; --i) {
      for (int j = N - 2; j >= 0; --j) {
        int a = dp[i + 1][j] + points[i][j];
        int b = dp[i][j + 1] + points[i][j];
        if (a >= 0 || b >= 0) {
          dp[i][j] = 0;
        } else {
          dp[i][j] = max(a, b);
        }
      }
    }

    return dp[0][0] > 0 ? 1 : 1 - dp[0][0];
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> a(m, vector<int>(n));

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        cin >> a[i][j];

    Solution ob;
    cout << ob.minPoints(a, m, n) << "\n";
  }
  return 0;
}

// } Driver Code Ends
