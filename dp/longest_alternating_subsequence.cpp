//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  int AlternatingaMaxLength(vector<int> &nums) {
    // Code here
    int n = nums.size();
    vector<int> dp(n, 1), dp2(n, 1);
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        dp[i] = max(dp[i], dp2[i - 1] + 1);
        dp2[i] = dp2[i - 1];
      } else if (nums[i] < nums[i - 1]) {
        dp2[i] = max(dp2[i], dp[i - 1] + 1);
        dp[i] = dp[i - 1];
      } else {
        dp2[i] = dp2[i - 1];
        dp[i] = dp[i - 1];
      }
    }
    int ans = *max_element(dp.begin(), dp.end());
    int ans2 = *max_element(dp2.begin(), dp2.end());
    // for(int i = 0; i < n; ++i) {
    //     cout << dp[i] << ' ' << dp2[i] << endl;
    // }
    return max(ans, ans2);
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
    Solution obj;
    int ans = obj.AlternatingaMaxLength(nums);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
