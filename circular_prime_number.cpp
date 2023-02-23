//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
class Solution {
  // } Driver Code Ends
  bool prime(int n) {
    if (n == 0 || n == 1) return false;
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) return false;
    }
    return true;
  }

 public:
  int isCircularPrime(int n) {
    // Code here
    int k = n;
    int len = 0;
    while (k) {
      ++len;
      k /= 10;
    }
    k = n;
    do {
      if (!prime(k)) return 0;
      k = pow(10, len - 1) * (k % 10) + k / 10;
    } while (k != n);
    return 1;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    Solution ob;
    int ans = ob.isCircularPrime(n);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
