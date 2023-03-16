//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  int n;
  int dp[101][101];

  int solve(const vector<int>& a, int i, int k) {
    if (k == 0) return 0;
    if (i == n) {
      return -1e9;
    }
    if (dp[i][k] != -1) return dp[i][k];
    int& ans = dp[i][k];
    ans = -1e9;
    for (int j = i + 1; j < n; ++j) {
      if (a[j] >= a[i]) {
        ans = max(ans, a[j] + solve(a, j, k - 1));
      }
    }
    return ans;
  }

 public:
  int max_sum(vector<int>& a, int k) {
    // Code here
    memset(dp, -1, sizeof(dp));
    n = a.size();
    int ans = INT_MIN;
    for (int i = 0; i < n; ++i) {
      ans = max(ans, a[i] + solve(a, i, k - 1));
    }
    if (ans < 0) return -1;
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    Solution ob;
    cout << ob.max_sum(v, k) << "\n";
  }
  return 0;
}

// } Driver Code Ends
