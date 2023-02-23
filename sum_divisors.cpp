//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
 public:
  long long int divSum(long long int n) {
    // code here
    long long ans = 0;
    for (int i = 1; i * i <= n; ++i) {
      if (n % i == 0) {
        ans += i;
        if (i * i != n && n / i != n) ans += n / i;
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    Solution ob;
    cout << ob.divSum(n) << endl;
  }
  return 0;
}

// } Driver Code Ends
