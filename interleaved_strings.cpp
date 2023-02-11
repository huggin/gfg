//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  string a, b, c;
  int dp[101][101];
  int solve(int i, int j, int k) {
    if (i == a.size() && j == b.size()) return 1;
    if (dp[i][j] != -1) return dp[i][j];
    if (i == a.size()) {
      if (b[j] != c[k])
        return 0;
      else {
        return solve(i, j + 1, k + 1);
      }
    }
    if (j == b.size()) {
      if (a[i] != c[k])
        return 0;
      else {
        return solve(i + 1, j, k + 1);
      }
    }
    if (a[i] == c[k]) {
      int t = solve(i + 1, j, k + 1);
      if (t == 1) return dp[i][j] = 1;
    }
    if (b[j] == c[k]) {
      int t = solve(i, j + 1, k + 1);
      if (t == 1) return dp[i][j] = 1;
    }
    return dp[i][j] = 0;
  }

 public:
  /*You are required to complete this method */
  bool isInterleave(string A, string B, string C) {
    // Your code here
    a = A;
    b = B;
    c = C;
    memset(dp, -1, sizeof(dp));
    return solve(0, 0, 0);
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    string a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    Solution obj;
    cout << obj.isInterleave(a, b, c) << endl;
  }
  // your code goes here
  return 0;
}
// } Driver Code Ends
