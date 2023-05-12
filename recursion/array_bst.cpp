//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  void go(vector<int> &n, int l, int r, vector<int> &ans) {
    if (l > r)
      return;
    int m = l + (r - l) / 2;
    ans.push_back(n[m]);
    go(n, l, m - 1, ans);
    go(n, m + 1, r, ans);
  }

public:
  vector<int> sortedArrayToBST(vector<int> &nums) {
    // Code here
    vector<int> ans;
    go(nums, 0, nums.size() - 1, ans);
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
    vector<int> ans = obj.sortedArrayToBST(nums);
    for (auto i : ans)
      cout << i << " ";
    cout << "\n";
  }
  return 0;
}
// } Driver Code Ends
