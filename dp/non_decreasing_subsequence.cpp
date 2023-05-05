//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  vector<vector<int>> dp;
  int n;
  int oo = 1000000000;

  int solve(int a[], int i, int k) {
    if (k == 0)
      return 0;
    if (i == n)
      return oo;
    // if (k == 1 && i == n-1) return a[n-1];
    if (dp[i][k] != -1)
      return dp[i][k];
    int &ans = dp[i][k];
    ans = oo;
    for (int j = i + 1; j < n; ++j) {
      if (a[j] >= a[i]) {
        ans = min(ans, a[j] + solve(a, j, k - 1));
      }
    }
    return ans;
  }

public:
  int minSum(int arr[], int N, int K) {
    // Your code goes here
    dp.assign(N, vector<int>(K + 1, -1));

    n = N;
    int ans = oo;
    for (int i = 0; i < N; ++i) {
      ans = min(ans, arr[i] + solve(arr, i, K - 1));
    }
    // cout << ans << endl;
    if (ans >= oo)
      return -1;
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;

    int a[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];

    Solution ob;
    cout << ob.minSum(a, n, k) << "\n";
  }
  return 0;
}

// } Driver Code Ends
