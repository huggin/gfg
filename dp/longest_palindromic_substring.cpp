//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
public:
  string longestPalindrome(string S) {
    // code here
    int n = S.size();
    vector<vector<int>> dp(n);
    for (int i = 0; i < n; ++i) {
      dp[i].assign(n, 1);
    }
    int max_len = 1;
    int left = 0, right = 0;
    for (int k = 1; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        int j = i + k;
        if (j >= n)
          continue;
        if (j == i + 1 && S[j] == S[i]) {
          if (max_len < j - i + 1) {
            left = i;
            right = j;
            max_len = j - i + 1;
          }
          dp[i][j] = 1;
        } else if (j > i + 1 && S[j] == S[i] && dp[i + 1][j - 1] == 1) {
          dp[i][j] = 1;
          if (max_len < j - i + 1) {
            left = i;
            right = j;
            max_len = j - i + 1;
          }
        } else {
          dp[i][j] = 0;
        }
      }
    }

    return S.substr(left, right - left + 1);
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
    cout << ob.longestPalindrome(S) << endl;
  }
  return 0;
}

// } Driver Code Ends
