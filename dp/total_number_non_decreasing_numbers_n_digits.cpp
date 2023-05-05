//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  long long dp[501][10];
  int n;

  long long solve(int k, int d) {
    if (k == n)
      return 1;
    if (dp[k][d] != -1)
      return dp[k][d];
    long long &ans = dp[k][d];
    ans = 0;
    for (int i = d; i <= 9; ++i) {
      ans += solve(k + 1, i);
    }
    return ans;
  }

public:
  long long int count(int N) {
    // code
    if (N == 1)
      return 10;
    n = N;
    memset(dp, -1, sizeof(dp));
    long long ans = 0;
    for (int i = 0; i < 10; ++i) {
      ans += solve(1, i);
    }
    return ans;
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
    cout << ob.count(N) << "\n";
  }
  return 0;
}
// } Driver Code Ends
