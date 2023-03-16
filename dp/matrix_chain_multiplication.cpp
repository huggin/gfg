//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  int matrixMultiplication(int N, int arr[]) {
    // code here
    vector<vector<int>> dp(N, vector<int>(N));
    for (int i = 0; i < N - 2; ++i) {
      dp[i][i + 2] = arr[i] * arr[i + 1] * arr[i + 2];
    }
    for (int k = 3; k < N; ++k) {
      for (int i = 0; i < N - k; ++i) {
        dp[i][i + k] = INT_MAX;
        for (int j = i + 1; j < i + k; ++j) {
          dp[i][i + k] = min(dp[i][i + k], dp[i][j] + dp[j][i + k] +
                                               arr[i] * arr[i + k] * arr[j]);
        }
      }
    }
    return dp[0][N - 1];
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++) cin >> arr[i];

    Solution ob;
    cout << ob.matrixMultiplication(N, arr) << endl;
  }
  return 0;
}
// } Driver Code Ends