//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  int minTimeForWritingChars(int N, int I, int D, int C) {
    // Your code goes here
    vector<int> dp(N + 1, INT_MAX);
    dp[0] = 0;
    dp[1] = I;
    for (int i = 2; i <= N; ++i) {
      dp[i] = min(dp[i], dp[i - 1] + I);
      if (i % 2 == 0)
        dp[i] = min(dp[i], dp[i / 2] + C);
      else
        dp[i] = min(dp[i], dp[(i + 1) / 2] + C + D);
    }
    return dp[N];
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, i, d, c;
    cin >> n >> i >> d >> c;

    Solution ob;
    cout << ob.minTimeForWritingChars(n, i, d, c) << "\n";
  }
  return 0;
}

// } Driver Code Ends
