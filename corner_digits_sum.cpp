//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  int corner_digitSum(int n) {
    // Code here
    if (n < 10) return n;
    int ans = n % 10;
    while (n >= 10) {
      n /= 10;
    }
    return ans + n;
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
    int ans = ob.corner_digitSum(n);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
