//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  long long countDivisibleSubstring(string s) {
    // Your code goes here
    int n = s.size();
    vector<vector<int>> dp(3, vector<int>(n + 1));
    for (int i = 0; i < n; ++i) {
      int t = s[i] - '0';
      dp[t % 3][i + 1] += dp[0][i];
      dp[(t + 1) % 3][i + 1] += dp[1][i];
      dp[(t + 2) % 3][i + 1] += dp[2][i];
      dp[t % 3][i + 1]++;
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '8') {
        ++ans;
      }
      if (i - 1 >= 0) {
        int x = (s[i - 1] - '0') * 10 + s[i] - '0';
        if (x % 8 == 0 && x % 3 != 0) {
          ++ans;
        }
      }
      if (i - 2 >= 0) {
        int x = (s[i - 2] - '0') * 100 + (s[i - 1] - '0') * 10 + s[i] - '0';
        int y = (s[i - 2] - '0') + (s[i - 1] - '0') + s[i] - '0';
        if (x % 8 == 0 && y % 3 != 0) {
          ++ans;
        }
        if (x % 8 == 0) {
          if (y % 3 == 0) {
            ans += dp[1][i - 2] + dp[2][i - 2];
          } else if (y % 3 == 1) {
            ans += dp[0][i - 2] + dp[1][i - 2];
          } else {
            ans += dp[0][i - 2] + dp[2][i - 2];
          }
        }
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
    string str;
    cin >> str;

    Solution ob;
    cout << ob.countDivisibleSubstring(str);
    cout << "\n";
  }
  return 0;
}
// } Driver Code Ends
