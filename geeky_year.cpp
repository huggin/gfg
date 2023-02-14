//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  int Count(int a, int b) {
    // Code here
    vector<int> dp(3001);
    dp[2001] = 1;
    for (int i = 2002; i <= 3000; ++i) {
      int y = 365;
      if ((i - 1) % 100 == 0 && (i - 1) % 400 == 0 ||
          (i - 1) % 4 == 0 && (i - 1) % 100 != 0) {
        y = 366;
      }
      dp[i] = (dp[i - 1] + y % 7) % 7;
    }
    for (int i = 2000; i >= 1000; --i) {
      int y = 365;
      if ((i) % 100 == 0 && (i) % 400 == 0 || (i) % 4 == 0 && (i) % 100 != 0) {
        y = 366;
      }
      dp[i] = (dp[i + 1] - y % 7 + 7) % 7;
    }
    int ans = 0;
    for (int i = a; i <= b; ++i) {
      if (dp[i] == 0) ++ans;
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int a, b;
    cin >> a >> b;
    Solution obj;
    int ans = obj.Count(a, b);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
