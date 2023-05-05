//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  int dp[101][1000];
  string s;

  int solve(int k, int sum) {
    if (k == s.size())
      return 1;
    if (dp[k][sum] != -1)
      return dp[k][sum];
    int &ans = dp[k][sum];
    ans = 0;
    int t = 0;
    for (int i = k; i < s.size(); ++i) {
      t += s[i] - '0';
      if (t >= sum) {
        ans += solve(i + 1, t);
      }
    }
    return ans;
  }

public:
  int TotalCount(string str) {
    // Code here
    memset(dp, -1, sizeof(dp));
    s = str;
    return solve(0, 0);
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    string str;
    cin >> str;
    Solution ob;
    int ans = ob.TotalCount(str);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
