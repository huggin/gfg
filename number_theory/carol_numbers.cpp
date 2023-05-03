//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  long long nthCarolNumber(long long n) {
    // code here
    const int M = 1e9 + 7;
    long long ans = 1;
    long long a = 2;
    while (n) {
      if (n & 1) {
        ans = (ans * a) % M;
      }
      a = a * a % M;
      n >>= 1;
    }
    return ((ans - 1) * (ans - 1) % M + M - 2) % M;
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
    cout << ob.nthCarolNumber(n) << endl;
  }
  return 0;
}
// } Driver Code Ends
