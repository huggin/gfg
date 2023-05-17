//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  vector<int> fact;

  long long inv(long long d, int p) {
    long long ans = 1;
    int b = p - 2;
    while (b) {
      if (b & 1)
        ans = ans * d % p;
      d = (d % p) * (d % p) % p;
      b >>= 1;
    }
    return ans;
  }

  int nCrLucas(int n, int r, int p) {
    fact.assign(p + 1, 1);
    for (int i = 1; i <= p; ++i)
      fact[i] = fact[i - 1] * i % p;

    long long ans = 1;
    while (n) {
      int n0 = n % p;
      int r0 = r % p;
      if (r0 > n0)
        return 0;
      ans = ans * fact[n0] * inv((fact[r0] * fact[n0 - r0]) % p, p) % p;
      n /= p;
      r /= p;
    }
    return ans;
  }

public:
  int nCrModM(int n, int r, int m) {
    // Code here
    int M = m;
    vector<int> prime;
    vector<int> a;

    for (int i = 2; i * i <= m; ++i) {
      if (m % i == 0) {
        prime.push_back(i);
        m /= i;
      }
    }
    if (m != 1)
      prime.push_back(m);

    for (int i = 0; i < prime.size(); ++i) {
      a.push_back(nCrLucas(n, r, prime[i]));
    }

    // Chinese remainder theorem
    int ans = 0;
    for (int i = 0; i < prime.size(); ++i) {
      int t = inv(M / prime[i], prime[i]);
      ans = ((ans + M / prime[i] * a[i] % M * t) % M);
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n, r, m;
    cin >> n >> r >> m;
    Solution obj;
    int ans = obj.nCrModM(n, r, m);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
