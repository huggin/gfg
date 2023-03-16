//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  const int M = 1e9 + 7;
  vector<vector<int>> dp;

  int solve(int a[], int k, int sum) {
    if (k < 0) {
      if (sum == 0)
        return 1;
      else
        return 0;
    }

    if (dp[k][sum] != -1) return dp[k][sum];
    int& ans = dp[k][sum];
    ans = solve(a, k - 1, sum);
    if (sum >= a[k]) {
      ans = (ans + solve(a, k - 1, sum - a[k])) % M;
    }
    return ans;
  }

 public:
  int perfectSum(int arr[], int n, int sum) {
    // Your code goes here
    dp.assign(n, vector<int>(sum + 1, -1));
    return solve(arr, n - 1, sum);
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, sum;

    cin >> n >> sum;

    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    Solution ob;
    cout << ob.perfectSum(a, n, sum) << "\n";
  }
  return 0;
}

// } Driver Code Ends
