//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  int MinCoin(vector<int> nums, int amount) {
    // Code here
    int dp[amount + 1];
    for (int i = 1; i <= amount; ++i) {
      dp[i] = 1000000;
    }
    dp[0] = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < amount; ++i) {
      for (int j = 0; j < nums.size(); ++j) {
        if (i + nums[j] <= amount) {
          dp[i + nums[j]] = min(dp[i + nums[j]], dp[i] + 1);
        }
      }
    }

    if (dp[amount] >= 1000000) return -1;
    return dp[amount];
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n, amount;
    cin >> n >> amount;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution ob;
    int ans = ob.MinCoin(nums, amount);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
