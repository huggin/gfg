//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  bool is_prime(int n) {
    if (n < 3) return true;
    for (int i = 2; i * i <= n; ++i)
      if (n % i == 0) return false;
    return true;
  }

 public:
  long long primeProduct(long long L, long long R) {
    // code here
    const int M = 1e9 + 7;
    long long ans = 1;
    for (auto i = L; i <= R; ++i) {
      if (is_prime(i)) ans = (ans * i) % M;
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long L, R;
    cin >> L >> R;

    Solution ob;
    cout << ob.primeProduct(L, R) << "\n";
  }
  return 0;
}
// } Driver Code Ends
