//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function template for C++
class Solution {
public:
  int palindromicStrings(int N, int K) {
    // Your code goes here
    const int mod = 1e9 + 7;
    long long dp[N + 1];
    dp[0] = 0;
    dp[1] = K;
    dp[2] = K;
    for (int i = 3; i <= N; ++i) {
      dp[i] = (dp[i - 2] * (K - (i - 1) / 2)) % mod;
    }
    long long ans = 0;
    for (int i = 1; i <= N; ++i) {
      ans = (ans + dp[i]) % mod;
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;

    Solution ob;

    cout << ob.palindromicStrings(n, k) << "\n";
  }

  return 0;
}
// } Driver Code Ends
