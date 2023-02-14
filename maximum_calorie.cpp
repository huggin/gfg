//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  vector<int> dp[3];
  int N;

  int solve(int a[], int k, int u) {
    if (k == N) return 0;
    if (dp[u][k] != -1) return dp[u][k];
    int& ans = dp[u][k];
    if (u == 2) {
      ans = solve(a, k + 1, 0);
    } else {
      ans = max(a[k] + solve(a, k + 1, u + 1), solve(a, k + 1, 0));
    }
    return ans;
  }

 public:
  int maxCalories(int arr[], int n) {
    // Your code goes here
    N = n;
    dp[0].assign(n, -1);
    dp[1].assign(n, -1);
    dp[2].assign(n, -1);

    return solve(arr, 0, 0);
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
    for (int i = 0; i < n; i++) cin >> a[i];

    Solution ob;
    cout << ob.maxCalories(a, n) << "\n";
  }
  return 0;
}
// } Driver Code Ends
