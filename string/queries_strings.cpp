//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  vector<vector<int>> dp;
  int solve(int i, int j) {
    if (i < 0) {
      int ans = 0;
      for (int k = 0; k < 26; ++k) {
        if (dp[j][k] > 0) {
          ++ans;
        }
      }
      return ans;
    }
    int ans = 0;
    for (int k = 0; k < 26; ++k) {
      if (dp[j][k] > dp[i][k]) {
        ++ans;
      }
    }
    return ans;
  }

public:
  vector<int> SolveQueris(string str, vector<vector<int>> Query) {
    // Code here
    int n = str.size();
    dp.assign(n, vector<int>(26));
    dp[0][str[0] - 'a']++;
    for (int i = 1; i < n; ++i) {
      copy(dp[i - 1].begin(), dp[i - 1].end(), dp[i].begin());
      dp[i][str[i] - 'a']++;
    }
    vector<int> ans;
    for (auto q : Query) {
      ans.push_back(solve(q[0] - 2, q[1] - 1));
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    string str;
    cin >> str;
    int q;
    cin >> q;
    vector<vector<int>> Query;
    for (int i = 0; i < q; i++) {
      int l, r;
      cin >> l >> r;
      Query.push_back({l, r});
    }
    Solution obj;
    vector<int> ans = obj.SolveQueris(str, Query);
    for (auto i : ans)
      cout << i << " ";
    cout << "\n";
  }
  return 0;
}
// } Driver Code Ends
