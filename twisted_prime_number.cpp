//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  bool prime(int n) {
    if (n == 0 || n == 1) return false;
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) return false;
    }
    return true;
  }

  int reverse(int n) {
    int ans = 0;
    while (n) {
      ans = ans * 10 + n % 10;
      n /= 10;
    }
    return ans;
  }

 public:
  int isTwistedPrime(int N) {
    // code here
    return prime(N) && prime(reverse(N));
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    Solution ob;
    cout << ob.isTwistedPrime(N) << "\n";
  }
}
// } Driver Code Ends
