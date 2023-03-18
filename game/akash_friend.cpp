//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  string Play(vector<int> nums, int k) {
    // Code here
    int ans = 0;
    for (int i : nums) {
      while (i) {
        ++ans;
        i /= k;
      }
    }
    return ans % 2 ? "Akash" : "Friend";
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution ob;
    string ans = ob.Play(nums, k);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
