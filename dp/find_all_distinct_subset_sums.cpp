//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  vector<int> DistinctSum(vector<int> nums) {
    // Code here
    int sum = accumulate(nums.begin(), nums.end(), 0);
    vector<int> dp(sum + 1);
    dp[0] = 1;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = sum; j - nums[i] >= 0; --j) {
        if (dp[j - nums[i]] == 1) {
          dp[j] = 1;
        }
      }
    }
    vector<int> ans;
    for (int i = 0; i <= sum; ++i) {
      if (dp[i])
        ans.push_back(i);
    }
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
    Solution obj;
    vector<int> ans = obj.DistinctSum(nums);
    for (auto i : ans)
      cout << i << " ";
    cout << "\n";
  }
  return 0;
}

// } Driver Code Ends
