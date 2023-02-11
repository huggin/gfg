//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  int minThrow(int N, int arr[]) {
    // code here
    int ladder[31] = {0};
    int snake[31] = {0};
    for (int i = 0; i < N * 2; i += 2) {
      if (arr[i] < arr[i + 1]) {
        ladder[arr[i]] = arr[i + 1];
      } else {
        snake[arr[i]] = arr[i + 1];
      }
    }
    vector<int> dp(31, 100);
    dp[1] = 0;
    for (int i = 1; i <= 30; ++i) {
      for (int j = i + 1; j <= min(i + 6, 30); ++j) {
        dp[j] = min(dp[j], dp[i] + 1);
        if (ladder[j] != 0) {
          dp[ladder[j]] = min(dp[ladder[j]], dp[j]);
        }
        if (snake[j] != 0) {
          dp[snake[j]] = min(dp[snake[j]], dp[j]);
          dp[j] = 100;
        }
      }
      // cout << i << ' ' << dp[i] << endl;
    }
    return dp[30];
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    int arr[2 * N];
    for (int i = 0; i < 2 * N; i++) cin >> arr[i];

    Solution ob;
    cout << ob.minThrow(N, arr) << "\n";
  }
  return 0;
}
// } Driver Code Ends
