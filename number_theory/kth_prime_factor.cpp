//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  int kthPrime(int n, int k) {
    // code here
    for (int i = 2; i <= n; ++i) {
      while (n % i == 0) {
        if (--k == 0)
          return i;
        n /= i;
      }
    }
    return -1;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;

    Solution ob;
    cout << ob.kthPrime(n, k) << "\n";
  }
  return 0;
}
// } Driver Code Ends
