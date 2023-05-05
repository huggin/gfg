//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  int maxAmount(int arr[], int n) {
    // Your code goes here
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
      dp[i][i] = arr[i];

    for (int k = 1; k < n; ++k) {
      for (int i = 0; i + k < n; ++i) {
        if (k == 1) {
          dp[i][i + 1] = max(arr[i], arr[i + 1]);
        } else {
          int l = arr[i] + min(dp[i + 1][i + k - 1], dp[i + 2][i + k]);
          int r = arr[i + k] + min(dp[i][i + k - 2], dp[i + 1][i + k - 1]);
          dp[i][i + k] = max(l, r);
        }
      }
    }
    return dp[0][n - 1];
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];

    Solution ob;
    cout << ob.maxAmount(a, n) << "\n";
  }
  return 0;
}

// } Driver Code Ends
