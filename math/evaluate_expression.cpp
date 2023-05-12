//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  int evaluate_exp(int n) {
    // Code here
    vector<int> f(n + 2);
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i < n + 2; ++i) {
      f[i] = f[i - 1] + f[i - 2];
    }
    return f[n - 1] * f[n + 1] - f[n] * f[n];
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
    int ans = ob.evaluate_exp(n);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
