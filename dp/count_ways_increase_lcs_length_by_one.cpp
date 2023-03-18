//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  int dp[102][102];
  int dp2[102][102];
  int n1, n2;

  int solve(const string& s1, const string& s2, int i, int j) {
    if (i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int& ans = dp[i][j];
    if (s1[i] == s2[j]) {
      ans = 1 + solve(s1, s2, i - 1, j - 1);
    } else {
      ans = max(solve(s1, s2, i - 1, j), solve(s1, s2, i, j - 1));
    }
    return ans;
  }

  int solve2(const string& s1, const string& s2, int i, int j) {
    if (i == n1 || j == n2) return 0;
    if (dp2[i][j] != -1) return dp2[i][j];
    int& ans = dp2[i][j];
    if (s1[i] == s2[j]) {
      ans = 1 + solve2(s1, s2, i + 1, j + 1);
    } else {
      ans = max(solve2(s1, s2, i + 1, j), solve2(s1, s2, i, j + 1));
    }
    return ans;
  }

 public:
  int waysToIncreaseLCSBy1(int N1, string S1, int N2, string S2) {
    // code here
    memset(dp, -1, sizeof(dp));
    int lcs = solve(S1, S2, N1 - 1, N2 - 1);
    memset(dp2, -1, sizeof(dp2));
    n1 = N1, n2 = N2;
    int lcs2 = solve2(S1, S2, 0, 0);
    // cout << lcs2 << ' ' << lcs << endl;
    int ans = 0;
    set<pair<int, char>> s;
    for (int j = 0; j < N2; ++j) {
      for (char c = 'a'; c <= 'z'; ++c) {
        if (S2[j] != c) continue;
        for (int i = 0; i <= N1; ++i) {
          if (solve(S1, S2, i - 1, j - 1) + solve2(S1, S2, i, j + 1) == lcs) {
            // cout << c << ' ' << j << ' ' << i << endl;
            if (s.find(make_pair(i, c)) == s.end()) {
              ++ans;
              s.emplace(i, c);
            }
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
    int n1, n2;
    cin >> n1 >> n2;
    string s1, s2;
    cin >> s1 >> s2;
    Solution ob;
    cout << ob.waysToIncreaseLCSBy1(n1, s1, n2, s2) << endl;
  }
  return 0;
}
// } Driver Code Ends
