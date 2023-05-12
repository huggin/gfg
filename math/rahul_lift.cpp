//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  int noOfWays(int z, int n, int m) {
    // Code here
    const int M = 1e9 + 7;
    long long ans = 1;
    long long k = z - 1;
    for (int i = 1; i <= m; ++i) {
      ans = (ans * k) % M;
      ++k;
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n, z, m;
    cin >> z >> n >> m;
    Solution obj;
    int ans = obj.noOfWays(z, n, m);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
