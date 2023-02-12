//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  int DivisibleByM(vector<int> nums, int m) {
    // Code here
    int total = 0;
    for (auto& a : nums) {
      if (a % m == 0) return 1;
      a %= m;
      total += a;
    }
    vector<int> dp(total + 1);
    dp[0] = 1;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = total; j - nums[i] >= 0; --j) {
        if (dp[j - nums[i]] == 1) {
          dp[j] = 1;
          if (j % m == 0) return 1;
        }
      }
    }
    return 0;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution ob;
    int ans = ob.DivisibleByM(nums, m);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
