//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  int dp[500];
  int K;
  vector<int> a;
  int n;

  int solve(int k) {
    if (k == n) return 0;
    if (dp[k] != -1) return dp[k];
    if (accumulate(a.begin() + k, a.end(), n - k - 1) <= K) return dp[k] = 0;

    int& ans = dp[k];
    ans = INT_MAX;
    int t = 0;
    for (int i = k; i < n; ++i) {
      t += a[i];
      if (t <= K) {
        ans = min(ans, (K - t) * (K - t) + solve(i + 1));
        t++;
      } else {
        break;
      }
    }
    return ans;
  }

 public:
  int solveWordWrap(vector<int> nums, int k) {
    // Code here
    memset(dp, -1, sizeof(dp));
    K = k;
    a = nums;
    n = nums.size();
    return solve(0);
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cin >> k;
    Solution obj;
    cout << obj.solveWordWrap(nums, k) << endl;
  }
  return 0;
}
// } Driver Code Ends
