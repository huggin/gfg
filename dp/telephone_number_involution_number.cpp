//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  long long telephoneNum(long long n) {
    // code here
    int const mod = 1e9 + 7;
    vector<long long> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
      dp[i] = (dp[i - 1] + (i - 1) * dp[i - 2]) % mod;
    }
    return dp[n];
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;

    Solution ob;
    cout << ob.telephoneNum(n) << "\n";
  }
  return 0;
}
// } Driver Code Ends
