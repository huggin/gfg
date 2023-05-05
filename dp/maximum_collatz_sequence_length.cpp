//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  int collatzLength(int N) {
    // code here
    vector<int> dp(N + 1);
    dp[1] = 1;
    int ans = 1;
    for (int i = 2; i <= N; ++i) {
      int j = i;
      int cnt = 0;

      while (j >= i) {
        if (j % 2 == 0) {
          cnt++;
          j /= 2;
        } else {
          cnt += 2;
          j = (3 * j + 1) / 2;
        }
      }
      dp[i] += dp[j] + cnt;

      ans = max(ans, dp[i]);
    }

    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;

    Solution ob;
    cout << ob.collatzLength(N) << "\n";
  }
  return 0;
}
// } Driver Code Ends
