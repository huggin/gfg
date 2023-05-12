//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  vector<int> dp;
  int solve(int k) {
    if (dp[k] != -1)
      return dp[k];
    dp[k] = 0;
    for (int i = 1; i < k; ++i) {
      if (k % i == 0) {
        if (!solve(k - i)) {
          return dp[k] = 1;
        }
      }
    }
    return dp[k];
  }

public:
  bool divisorGame(int N) {
    // code here
    dp.assign(N + 1, -1);
    return solve(N);
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;

    Solution obj;
    bool ans = obj.divisorGame(N);
    if (ans)
      cout << "True" << endl;
    else
      cout << "False" << endl;
  }
  return 0;
}
// } Driver Code Ends
