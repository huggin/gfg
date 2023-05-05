//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  vector<int> n;
  vector<unordered_map<int, int>> dp;
  int solve(int k, int prev) {
    if (k == n.size())
      return 0;
    if (dp[k].find(prev) != dp[k].end())
      return dp[k][prev];

    int &ans = dp[k][prev];
    int l = INT_MAX, r = INT_MAX;

    l = min(l, 1 + solve(k + 1, prev + 1));

    if (n[k] > prev) {
      r = min(r, solve(k + 1, n[k]));
    } else {
      r = min(r, 1 + solve(k + 1, prev + 1));
    }
    ans = min(l, r);
    return ans;
  }

public:
  int min_operations(vector<int> nums) {
    // Code here
    n = nums;
    dp.clear();
    dp.resize(n.size());
    int ans = solve(0, -2000);
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];
    Solution ob;
    int ans = ob.min_operations(nums);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
