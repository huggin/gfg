//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  string longestSubstring(string S, int N) {
    // code here
    vector<vector<int>> dp(N + 1, vector<int>(N + 1));
    int ma = 0, index = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
        if (S[i] == S[j]) {
          dp[i + 1][j + 1] = 1 + dp[i][j];
          if (j - i < dp[i + 1][j + 1]) continue;

          if (ma < dp[i + 1][j + 1]) {
            ma = dp[i + 1][j + 1];
            index = i + 1 - ma;
          }
        }
      }
    }
    if (ma == 0) return "-1";
    return S.substr(index, ma);
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    string S;

    cin >> N;
    cin >> S;

    Solution ob;
    cout << ob.longestSubstring(S, N) << endl;
  }
  return 0;
}
// } Driver Code Ends
