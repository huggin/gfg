//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  vector<int> dp[2];
  int n;
  int* a;

  int solve(int k, int ma) {
    if (k >= n - 1) return 0;
    if (dp[ma][k] != -1) return dp[ma][k];
    int& ans = dp[ma][k];
    if (ma == 0) {
      ans = max(solve(k + 1, 0), solve(k + 1, 1) + abs(a[k + 1] - 1));
    } else {
      ans = max(solve(k + 1, 0) + abs(a[k] - 1),
                solve(k + 1, 1) + abs(a[k + 1] - a[k]));
    }
    // cout << k << ' ' << ma << ' ' << ans << '\n';
    return ans;
  }

 public:
  int maximumDifferenceSum(int arr[], int N) {
    // Your code goes here
    dp[0].assign(N, -1);
    dp[1].assign(N, -1);
    n = N;
    a = arr;
    return max(solve(0, 0), solve(0, 1));
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
    cout << ob.maximumDifferenceSum(a, n) << "\n";
  }
  return 0;
}

// } Driver Code Ends
