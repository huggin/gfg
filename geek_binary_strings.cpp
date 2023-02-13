//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  const int M = 1000000007;

  int inv(int i) {
    return i <= 1 ? i : M - (long long)(M / i) * inv(M % i) % M;
  }

 public:
  int prefixStrings(int N) {
    // Your code goes here
    vector<long long> dp(N + 1);
    dp[0] = 1;
    for (int i = 1; i <= N; ++i) {
      dp[i] = ((2 * (2 * i - 1) * dp[i - 1]) % M * inv(i + 1)) % M;
    }
    return dp[N];
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
    cout << ob.prefixStrings(n);
    cout << "\n";
  }
  return 0;
}

// } Driver Code Ends
