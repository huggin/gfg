//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  int DivCountSum(int n) {
    // Code here
    vector<int> p(n + 1, 1);
    p[0] = p[1] = 0;

    for (int i = 2; i <= n; ++i) {
      for (int j = i + i; j <= n; j += i) {
        p[j]++;
      }
    }
    return accumulate(p.begin(), p.end(), n);
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
    int ans = obj.DivCountSum(n);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
