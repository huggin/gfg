//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  int NthTerm(int n) {
    // Code here
    const int M = 1e9 + 7;
    long long b = 1;
    for (int i = 2; i < n; ++i) {
      b = (b * i) % M;
    }
    return n * n * b % M;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    Solution obj;
    int ans = obj.NthTerm(n);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
