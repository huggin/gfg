//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  long long inv(long long d, int m) {
    long long ans = 1;
    int b = m - 2;
    while (b) {
      if (b & 1) ans = ans * d % m;
      d = (d % m) * (d % m) % m;
      b >>= 1;
    }
    return ans;
  }

  vector<long long> fact;

 public:
  int nCr(long long n, long long r) {
    // Code here
    const int M = 1000003;
    r = min(r, n - r);
    long long ans = 1;
    fact.assign(M + 1, 1);
    for (int i = 1; i <= M; ++i) fact[i] = fact[i - 1] * i % M;

    while (n) {
      if (n % M < r % M) return 0;
      ans = ans * fact[n % M] * inv(fact[r % M] * fact[(n - r) % M], M) % M;
      n /= M;
      r /= M;
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    long long n, r;
    cin >> n >> r;
    Solution obj;
    int ans = obj.nCr(n, r);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
