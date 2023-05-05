//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  int zigzagSequence(int n, vector<vector<int>> M) {
    // code here
    vector<vector<int>> dp(n, vector<int>(n));
    copy(M[0].begin(), M[0].end(), dp[0].begin());

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        dp[i][j] = INT_MIN;
        for (int k = 0; k < n; ++k) {
          if (j == k)
            continue;
          dp[i][j] = max(dp[i][j], M[i][j] + dp[i - 1][k]);
        }
      }
    }
    return *max_element(dp[n - 1].begin(), dp[n - 1].end());
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> M(n, vector<int>(n, -1));
    for (int i = 0; i < n * n; i++)
      cin >> M[i / n][i % n];

    Solution ob;
    cout << ob.zigzagSequence(n, M) << endl;
  }
  return 0;
}
// } Driver Code Ends
