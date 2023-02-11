//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  int maxLength(string S) {
    // code here
    int n = S.size();
    vector<int> dp(n);
    stack<int> s;
    for (int i = 0; i < n; ++i) {
      if (S[i] == '(') {
        s.push(i);
      } else {
        if (s.empty()) {
          dp[i] = 0;
          continue;
        } else {
          dp[i] = i - s.top() + 1;
          s.pop();
        }
      }
    }
    int ans = 0;
    for (int i = n - 1; i >= 0;) {
      if (dp[i] != 0) {
        int t = dp[i];
        while (dp[i - t] != 0) {
          t += dp[i - t];
        }
        ans = max(ans, t);
        i = i - t;
      } else {
        --i;
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    string S;
    cin >> S;

    Solution ob;
    cout << ob.maxLength(S) << "\n";
  }
  return 0;
}
// } Driver Code Ends
