//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  int minimizeSum(int n, vector<vector<int>>& triangle) {
    // Code here
    if (n == 1) return triangle[0][0];
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    dp[0][0] = triangle[0][0];
    int ans = INT_MAX;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j <= i; ++j) {
        dp[i][j] = INT_MAX;
        if (j < i) {
          dp[i][j] = min(dp[i][j], dp[i - 1][j] + triangle[i][j]);
        }
        if (j - 1 >= 0) {
          dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + triangle[i][j]);
        }
        if (i == n - 1) {
          ans = min(ans, dp[i][j]);
        }
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> triangle;

    for (int i = 0; i < n; i++) {
      vector<int> temp;
      for (int j = 0; j <= i; j++) {
        int x;
        cin >> x;
        temp.push_back(x);
      }
      triangle.push_back(temp);
    }
    Solution obj;
    cout << obj.minimizeSum(n, triangle) << "\n";
  }
  return 0;
}
// } Driver Code Ends
