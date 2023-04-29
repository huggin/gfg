//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  // Function to find the minimum number of swaps required to sort the array.
  int minSwaps(vector<int> &nums) {
    // Code here
    vector<pair<int, int>> t(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
      t[i] = make_pair(nums[i], i);
    }
    sort(t.begin(), t.end());
    int ans = 0;
    for (int i = 0; i < t.size(); ++i) {
      if (t[i].first != nums[i]) {
        int temp = t[i].second;
        while (temp < i) {
          temp = t[temp].second;
        }
        swap(nums[i], nums[temp]);
        ++ans;
      }
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
    int ans = obj.minSwaps(nums);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
