//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  double AverageOfAllSubsets(vector<int> nums) {
    // Code here
    int c[501][501];
    int n = nums.size();
    c[0][0] = 1;
    c[1][0] = c[1][1] = 1;
    for (int i = 2; i <= n; ++i) {
      c[i][0] = c[i][i] = 1;
      for (int j = 1; j < i; ++j) {
        c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
      }
    }
    int t = 0;
    for (int e : nums) {
      t += e;
    }
    double ans = 0;
    // t, n-1 * 2t / 2
    for (int i = 1; i <= n; ++i) {
      // cout << c[n][i] << ' ' << c[n][n-i] << ' ' << i << endl;
      ans += c[n - 1][i - 1] * t * 1.0 / i;
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
    Solution ob;
    double ans = ob.AverageOfAllSubsets(nums);
    cout << fixed << setprecision(6) << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
