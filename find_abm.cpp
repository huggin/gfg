//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  long long powerMod(string a, long long b, long long m) {
    // code here
    int n = a.size();
    long long d = 0;
    for (int i = 0; i < n; ++i) {
      d = (d * 10 + a[i] - '0') % m;
    }

    long long ans = 1 % m;
    while (b) {
      if (b & 1) ans = ans * d % m;
      d = d * d % m;
      b >>= 1;
    }

    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    string a;
    long long b, m;

    cin >> a >> b >> m;

    Solution ob;
    cout << ob.powerMod(a, b, m) << endl;
  }
  return 0;
}
// } Driver Code Ends
