//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  int mod = 1000000007;
  long long dp[61][61][61];
  long long fact[185];
  long long res = 0;

  long long binPow(long long b, int e) {
    e %= mod - 1;
    long long ans = 1;
    while (e > 0) {
      if (e & 1) ans = (ans * b) % mod;
      b = (b * b) % mod;
      e >>= 1;
    }
    return ans;
  }

  long long inv(int i, int j, int k) {
    long long t = fact[i + j + k];
    if (i < 0 || j < 0 || k < 0) return 0;
    t = t * binPow(fact[i], mod - 2) % mod;
    t = t * binPow(fact[j], mod - 2) % mod;
    t = t * binPow(fact[k], mod - 2) % mod;
    return t;
  }

  long long solve(int i, int j, int k) {
    if (i < 0 || j < 0 || k < 0) return 0;
    if (i == 0 && j == 0 && k == 0) return 0;
    // if (i == 1 && j == 0 && k == 0) return 4;
    // if (i == 0 && j == 1 && k == 0) return 5;
    // if (i == 0 && j == 0 && k == 1) return 6;
    if (dp[i][j][k] != -1) return dp[i][j][k];
    long long& ans = dp[i][j][k];
    ans = 0;
    ans = (ans + 10 * solve(i - 1, j, k) + 4 * inv(i - 1, j, k)) % mod;
    ans = (ans + 10 * solve(i, j - 1, k) + 5 * inv(i, j - 1, k)) % mod;
    ans = (ans + 10 * solve(i, j, k - 1) + 6 * inv(i, j, k - 1)) % mod;
    res = (res + ans) % mod;
    return ans;
  }

 public:
  int getSum(int X, int Y, int Z) {
    // Your code goes here
    memset(dp, -1, sizeof(dp));
    fact[0] = 1;
    for (int i = 1; i < 185; ++i) fact[i] = (fact[i - 1] * i) % mod;

    res = 0;
    solve(X, Y, Z);
    return res;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, y, z;
    cin >> x >> y >> z;

    Solution ob;
    cout << ob.getSum(x, y, z) << "\n";
  }
  return 0;
}

// } Driver Code Ends
