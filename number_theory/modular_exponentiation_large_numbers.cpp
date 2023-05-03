//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  long long int PowMod(long long int x, long long int n, long long int M) {
    // Code here
    if (n == 1)
      return x;
    if (x == 0)
      return 0;
    long long ans = PowMod(x, n / 2, M);
    ans = (ans * ans) % M;
    if (n % 2 == 1)
      ans = (ans * x) % M;
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long int x, n, m;
    cin >> x >> n >> m;
    Solution ob;
    long long int ans = ob.PowMod(x, n, m);
    cout << ans << "\n";
  }
  return 0;
}

// } Driver Code Ends
