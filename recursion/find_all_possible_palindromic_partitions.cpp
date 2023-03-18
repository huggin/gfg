//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  int dp[21][21];
  int n;
  vector<vector<string>> ans;
  vector<string> vs;
  string S;

  void solve(int k) {
    if (k == n) {
      ans.push_back(vs);
      return;
    }
    for (int i = k; i < n; ++i) {
      if (dp[k][i] == 1) {
        vs.push_back(S.substr(k, i - k + 1));
        solve(i + 1);
        vs.pop_back();
      }
    }
  }

 public:
  vector<vector<string>> allPalindromicPerms(string S) {
    // code here
    n = S.size();
    this->S = S;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) {
      dp[i][i] = 1;
    }
    for (int i = 1; i < n; ++i) {
      if (S[i - 1] == S[i]) {
        dp[i - 1][i] = 1;
      }
    }
    for (int k = 2; k < n; ++k) {
      for (int i = 0; i + k < n; ++i) {
        int j = i + k;
        if (S[i] == S[j] && dp[i + 1][j - 1] == 1) {
          dp[i][j] = 1;
        }
      }
    }
    ans.clear();
    solve(0);
    return ans;
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
    vector<vector<string>> ptr = ob.allPalindromicPerms(S);

    for (int i = 0; i < ptr.size(); i++) {
      for (int j = 0; j < ptr[i].size(); j++) {
        cout << ptr[i][j] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
// } Driver Code Ends
