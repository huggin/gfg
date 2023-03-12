//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
 public:
  long long subarraySum(long long a[], long long n) {
    // Your code goes here
    const int M = 1e9 + 7;
    long long ans = 0;

    for (long long i = 0; i < n; ++i) {
      long long k = min(i + 1, n - i);
      long long t = (k * (k + 1) * a[i] % M + (n - 2 * k) * k * a[i] % M) % M;
      ans = (ans + t) % M;
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n + 5];
    for (long long i = 0; i < n; i++) cin >> a[i];
    Solution ob;
    cout << ob.subarraySum(a, n) << endl;
  }
  return 0;
}

// } Driver Code Ends
