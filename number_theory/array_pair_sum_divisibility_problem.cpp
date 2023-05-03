//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  bool canPair(vector<int> nums, int k) {
    // Code here.
    if (nums.size() % 2 == 1)
      return false;
    int t = 0;
    vector<int> r(k);
    for (int i = 0; i < nums.size(); ++i) {
      r[nums[i] % k]++;
    }
    for (int i = 1; i < k; ++i) {
      if (r[i] != r[k - i])
        return false;
    }
    return r[0] % 2 == 0;
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
    for (int i = 0; i < nums.size(); i++)
      cin >> nums[i];
    Solution ob;
    bool ans = ob.canPair(nums, k);
    if (ans)
      cout << "True\n";
    else
      cout << "False\n";
  }
  return 0;
}
// } Driver Code Ends
