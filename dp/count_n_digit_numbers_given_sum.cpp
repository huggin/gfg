//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  vector<vector<long long>> dp;

  long long solve(int k, int sum) {
    if (sum < 0) return 0;
    if (sum == 0) return 1;
    if (k == 1 && sum <= 9) return 1;
    if (k == 0 && sum > 0) return 0;
    if (dp[k][sum] != -1) return dp[k][sum];
    long long& ans = dp[k][sum];
    ans = 0;
    for (int i = 0; i <= 9; ++i) {
      ans += solve(k - 1, sum - i);
      ans %= 1000000007;
    }
    return ans;
  }

 public:
  long int countWays(int n, int Sum) {
    // code here
    dp.assign(n + 1, vector<long long>(Sum + 1, -1));

    long long ans = 0;
    for (int i = 1; i <= 9; ++i) {
      ans += solve(n - 1, Sum - i);
      ans %= 1000000007;
    }
    return ans == 0 ? -1 : ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, Sum;
    cin >> n >> Sum;

    Solution ob;
    cout << ob.countWays(n, Sum) << endl;
  }
  return 0;
}
// } Driver Code Ends
