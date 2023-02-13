//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  int maxSum(int N, vector<vector<int>> mat) {
    // code here
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
      a[i] = max(mat[0][i], mat[1][i]);
      // cout << a[i] << ' ';
    }
    if (N == 1) return a[0];
    vector<int> dp(N);
    dp[0] = a[0];
    dp[1] = a[1];
    for (int i = 2; i < N; ++i) {
      dp[i] = dp[i - 2] + a[i];
      if (i - 3 >= 0) {
        dp[i] = max(dp[i], dp[i - 3] + a[i]);
      }
    }
    return max(dp[N - 1], dp[N - 2]);
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    vector<vector<int>> mat(2, vector<int>(N, 0));
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < N; j++) cin >> mat[i][j];
    }

    Solution ob;
    cout << ob.maxSum(N, mat) << "\n";
  }
  return 0;
}
// } Driver Code Ends
