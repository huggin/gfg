//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  int minCost(vector<vector<int>> &colors, int N) {
    // Write your code here.
    int dp[N][3];
    for (int i = 0; i < 3; ++i)
      dp[0][i] = colors[0][i];

    for (int i = 1; i < N; ++i) {
      for (int j = 0; j < 3; ++j) {
        dp[i][j] =
            min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + colors[i][j];
      }
    }
    return min({dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]});
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> colors(n, vector<int>(3));
    for (int i = 0; i < n; i++)
      cin >> colors[i][0] >> colors[i][1] >> colors[i][2];

    Solution ob;
    cout << ob.minCost(colors, n) << endl;
  }
}
// } Driver Code Ends
