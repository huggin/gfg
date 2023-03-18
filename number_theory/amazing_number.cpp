//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  bool prime(int n) {
    if (n == 0 || n == 1) return false;
    for (int i = 2; i * i <= n; ++i)
      if (n % i == 0) return false;
    return true;
  }

 public:
  long long isAmazing(long long n) {
    // code here
    long long k = sqrt(n);
    if (k * k != n) return 0;
    if (!prime(k)) return 0;
    return 1;
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
    cout << ob.isAmazing(n) << endl;
  }
  return 0;
}

// } Driver Code Ends
