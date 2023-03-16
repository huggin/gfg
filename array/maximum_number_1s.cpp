//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  int maxOnes(string s) {
    // Your code goes here
    int n = s.size();
    vector<int> dp(n);
    int ma = -1;
    int one = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        ++one;
        if (i == 0 || dp[i - 1] == 0) {
          dp[i] = 0;
        } else {
          dp[i] = dp[i - 1] - 1;
        }
      } else {
        if (i == 0 || dp[i - 1] == 0) {
          dp[i] = 1;
        } else {
          dp[i] = dp[i - 1] + 1;
        }
      }
      if (ma < dp[i]) {
        ma = dp[i];
      }
    }
    if (one == n) return n - 1;

    return one + ma;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;

    Solution ob;
    cout << ob.maxOnes(s) << "\n";
  }
  return 0;
}
// } Driver Code Ends
