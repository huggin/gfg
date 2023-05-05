//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  vector<vector<int>> dp;
  int N;
  int *a;

public:
  int minAdjustmentCost(int A[], int n, int target) {
    // Your code goes here
    dp.assign(n, vector<int>(101, -1));
    a = A;
    N = n;
    int ans = INT_MAX;
    for (int i = 0; i <= 100; ++i) {
      ans = min(ans, solve(0, i, target));
    }
    return ans;
  }

  int solve(int k, int v, int target) {
    if (k == N)
      return 0;
    if (dp[k][v] != -1)
      return dp[k][v];
    int &ans = dp[k][v];
    ans = abs(a[k] - v);
    int mi = INT_MAX;
    for (int i = 0; i <= 100; ++i) {
      if (abs(i - v) <= target) {
        int t = solve(k + 1, i, target);
        mi = min(mi, t);
      }
    }
    ans += mi;
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
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    Solution ob;
    cout << ob.minAdjustmentCost(a, n, k);

    cout << "\n";
  }
  return 0;
}

// } Driver Code Ends
