//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  vector<vector<int>> dp;
  string p, s;
  int solve(int i, int j) {
    if (i == p.size() && j == s.size()) {
      return 1;
    } else if (i == p.size() && j != s.size()) {
      return 0;
    } else if (i != p.size() && j == s.size()) {
      while (i < p.size()) {
        if (p[i++] != '*')
          return 0;
      }
      return 1;
    }
    if (dp[i][j] != -1) {
      return dp[i][j];
    }
    if (p[i] == '?' || p[i] == s[j]) {
      return dp[i][j] = solve(i + 1, j + 1);
    } else if (p[i] == '*') {
      return dp[i][j] = solve(i, j + 1) || solve(i + 1, j);
    } else {
      return dp[i][j] = 0;
    }
  }

public:
  /*You are required to complete this method*/
  int wildCard(string pattern, string str) {
    p = pattern;
    s = str;
    dp.assign(p.size(), vector<int>(s.size(), -1));
    return solve(0, 0);
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    string pat, text;
    cin >> pat;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> text;
    Solution obj;
    cout << obj.wildCard(pat, text) << endl;
  }
}

// } Driver Code Ends
