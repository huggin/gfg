//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  int LongestBitonicSequence(vector<int> nums) {
    // code here
    int g[1001] = {0}, l[1001] = {0};
    int n = nums.size();
    g[0] = 0;
    l[n - 1] = 0;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j]) {
          g[i] = max(g[i], g[j] + 1);
        }
      }
    }
    for (int i = n - 1; i >= 0; --i) {
      for (int j = n - 1; j > i; --j) {
        if (nums[i] > nums[j]) {
          l[i] = max(l[i], l[j] + 1);
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      // cout << g[i] << ' ' << l[i] << endl;
      ans = max(ans, g[i] + l[i] + 1);
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
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution ob;
    int ans = ob.LongestBitonicSequence(nums);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
