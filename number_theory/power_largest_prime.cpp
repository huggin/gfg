//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  __int128_t binpower(__int128_t a, __int128_t b, __int128_t n) {
    __int128_t ans = 1;
    while (b) {
      if (b & 1)
        ans = (ans * a) % n;
      a = a * a % n;
      b >>= 1;
    }
    return ans;
  }

  bool probablyPrimeFermat(__int128_t n, int iter = 3) {
    if (n < 4)
      return n == 2 || n == 3;

    for (int i = 0; i < iter; i++) {
      __int128_t a = 2 + rand() % (n - 3);

      __int128_t r = binpower(a, n - 1, n);
      if (r != 1)
        return false;
    }
    return true;
  }

public:
  int largePrime(long long n) {
    // code here
    if (probablyPrimeFermat(n))
      return 0;

    int ans = 0;
    for (long long i = 2; i * i <= n; ++i) {
      while (n % i == 0) {
        ++ans;
        n /= i;
      }
      if (n != 1)
        ans = 0;
    }
    if (n != 1)
      return 0;
    return ans > 1;
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
    if (ob.largePrime(n))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
// } Driver Code Ends
