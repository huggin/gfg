//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  int findWinner(int N, int X, int Y) {
    if (X > Y)
      swap(X, Y);
    // Your code goes here
    vector<int> dp(N + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 1; i <= N; ++i) {
      if (i == 1 || i == X || i == Y) {
        dp[i] = 1;
        continue;
      }
      dp[i] = 1 - dp[i - 1];
      if (i > X) {
        dp[i] |= 1 - dp[i - X];
      }
      if (i > Y) {
        dp[i] |= 1 - dp[i - Y];
      }
    }
    return dp[N];
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x, y;
    cin >> n >> x >> y;

    Solution ob;
    cout << ob.findWinner(n, x, y);
    cout << "\n";
  }
  return 0;
}
// } Driver Code Ends
