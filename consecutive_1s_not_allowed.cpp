//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
// User function template for C++
class Solution {
 public:
  // #define ll long long
  ll countStrings(int n) {
    // code here
    const int mod = 1e9 + 7;
    vector<ll> dp1(n), dp2(n);
    dp1[0] = 1;
    dp2[0] = 1;
    for (int i = 1; i < n; ++i) {
      dp1[i] = (dp1[i - 1] + dp2[i - 1]) % mod;
      dp2[i] = dp1[i - 1];
    }
    return (dp1[n - 1] + dp2[n - 1]) % mod;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    Solution ob;
    auto ans = ob.countStrings(n);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
