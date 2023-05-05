//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  double waterOverflow(int K, int R, int C) {
    // code here
    double dp[501][501] = {0};
    dp[1][1] = K;
    for (int i = 1; i <= R; ++i) {
      for (int j = 1; j <= C; ++j) {
        if (dp[i][j] > 1) {
          dp[i + 1][j] += (dp[i][j] - 1) / 2;
          dp[i + 1][j + 1] += (dp[i][j] - 1) / 2;
        }
      }
    }
    return dp[R][C] > 1 ? 1.0 : dp[R][C];
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int K, R, C;

    cin >> K >> R >> C;

    Solution ob;
    cout << fixed << setprecision(6) << ob.waterOverflow(K, R, C) << endl;
  }
  return 0;
}
// } Driver Code Ends
