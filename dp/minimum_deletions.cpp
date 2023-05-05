//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  int dp[1001][1001];
  int go(const string &s, int i, int j) {
    if (i >= j)
      return 0;
    if (dp[i][j] != -1)
      return dp[i][j];
    int &ans = dp[i][j];
    if (s[i] == s[j]) {
      ans = go(s, i + 1, j - 1);
    } else {
      ans = go(s, i + 1, j) + 1;
      ans = min(ans, go(s, i, j - 1) + 1);
    }
    return ans;
  }

public:
  int minimumNumberOfDeletions(string S) {
    // code here
    memset(dp, -1, sizeof(dp));
    return go(S, 0, S.size() - 1);
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    string S;
    cin >> S;
    Solution obj;
    cout << obj.minimumNumberOfDeletions(S) << endl;
  }
  return 0;
}
// } Driver Code Ends
