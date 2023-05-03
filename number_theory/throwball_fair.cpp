//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  vector<long long> fact;

public:
  long long int count(long long int N, long long int K, long long int M) {
    // code here
    long long n = N - 1;
    long long k = K - 1;
    k = min(k, n - k);
    long long ans = 1;
    fact.assign(M + 1, 1);
    for (int i = 1; i <= M; ++i)
      fact[i] = fact[i - 1] * i % M;

    while (n) {
      if (n % M < k % M)
        return 0;
      ans = ans * fact[n % M] * inv(fact[k % M] * fact[(n - k) % M], M) % M;
      n /= M;
      k /= M;
    }
    return ans;
  }

  long long inv(long long d, int m) {
    long long ans = 1;
    int b = m - 2;
    while (b) {
      if (b & 1)
        ans = ans * d % m;
      d = (d % m) * (d % m) % m;
      b >>= 1;
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int N;
    cin >> N;
    long long int K;
    cin >> K;
    long long int M;
    cin >> M;
    Solution ob;
    cout << ob.count(N, K, M) << endl;
  }
  return 0;
}
// } Driver Code Ends
