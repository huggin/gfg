//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  vector<int> dp;
  int solve(int k) {
    if (k == 1) return 0;
    if (dp[k] != -1) return dp[k];
    int& ans = dp[k];
    ans = 1 + solve(k - 1);
    if (k % 2 == 0) {
      ans = min(ans, 1 + solve(k / 2));
    }
    if (k % 3 == 0) {
      ans = min(ans, 1 + solve(k / 3));
    }
    return ans;
  }

 public:
  int minSteps(int N) {
    // Your code goes here
    dp.assign(N + 1, -1);
    return solve(N);
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    Solution ob;
    cout << ob.minSteps(n) << "\n";
  }
  return 0;
}

// } Driver Code Ends
