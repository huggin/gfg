//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  const int M = 1e9 + 7;
  long long dp[10001];
  long long solve(int n) {
    if (n == 1) return 1;
    if (n == 0) return 1;
    if (dp[n] != -1) return dp[n];
    long long &ans = dp[n];
    ans = (solve(n - 1) + solve(n - 2) * (n - 1)) % M;
    return ans;
  }

 public:
  int countFriendsPairings(int n) {
    // code here
    memset(dp, -1, sizeof(dp));
    return solve(n);
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
    cout << ob.countFriendsPairings(n);
    cout << endl;
  }
}

// } Driver Code Ends
