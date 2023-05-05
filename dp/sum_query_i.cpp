//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  vector<int> FindQuery(vector<int> nums, vector<vector<int>> Query) {
    // Code here
    int mod = 1000000007;
    int n = nums.size();
    vector<long long> dp(n + 1), dp1(n + 1), dp2(n + 1);
    dp[0] = 0;
    dp1[0] = dp2[0] = 0;
    for (long long i = 1; i <= n; ++i) {
      dp[i] = (dp[i - 1] + nums[i - 1]) % mod;
      dp1[i] = (dp1[i - 1] + i * nums[i - 1] % mod) % mod;
      dp2[i] = (dp2[i - 1] + (i * i) % mod * nums[i - 1] % mod) % mod;
    }
    // (l-r) i*i*arr[i] + 2*(1-l) epsilon(l, r) *i*arr[i]; + (1-l)*(l-1)*arr[i];
    vector<int> ans;
    for (auto &q : Query) {
      long long l = q[0];
      long long r = q[1];
      long long temp = 0;
      temp = ((dp2[r] - dp2[l - 1] + mod) % mod +
              (1 - l) * (1 - l) % mod * (dp[r] - dp[l - 1] + mod) % mod + mod -
              2 * (l - 1) * (dp1[r] - dp1[l - 1] + mod) % mod) %
             mod;

      ans.push_back(temp);
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n, q;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];
    cin >> q;
    vector<vector<int>> Query;
    for (int i = 0; i < q; i++) {
      int l, r;
      cin >> l >> r;
      Query.push_back({l, r});
    }
    Solution obj;
    vector<int> ans = obj.FindQuery(nums, Query);
    for (auto i : ans)
      cout << i << "\n";
  }
  return 0;
}
// } Driver Code Ends
