//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  int dp[100001];

  int solve(int k) {
    if (k == 2 || k == 3 || k == 4 || k == 5)
      return 1;
    if (dp[k] != -1)
      return dp[k];
    int &ans = dp[k];
    ans = 0;
    for (int i = 2; i <= 5; ++i) {
      if (!solve(k - i))
        return ans = 1;
    }
    for (int i = 2; i <= 5; ++i) {
      if (!solve(k / i))
        return ans = 1;
    }
    return ans;
  }

public:
  string divAndSub(int N) {
    // code here
    if (N == 1)
      return "Arya";
    memset(dp, -1, sizeof(dp));

    return solve(N) ? "Jon" : "Arya";
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;

    cin >> N;

    Solution ob;
    cout << ob.divAndSub(N) << endl;
  }
  return 0;
}
// } Driver Code Ends
