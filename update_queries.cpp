//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  vector<int> updateQuery(int N, int Q, vector<vector<int>> &U) {
    // code here
    vector<vector<int>> dp(17, vector<int>(N + 1));
    for (auto q : U) {
      int idx = 0;
      while (q[2]) {
        dp[idx][q[0] - 1] += q[2] % 2;
        dp[idx][q[1]] -= q[2] % 2;
        q[2] /= 2;
        ++idx;
      }
    }

    for (int i = 1; i < N; ++i) {
      for (int j = 0; j < 17; ++j) {
        dp[j][i] += dp[j][i - 1];
      }
    }

    vector<int> ans(N);
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < 17; ++j) {
        if (dp[j][i]) {
          ans[i] |= (1 << j);
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
    int n, q;
    cin >> n >> q;
    vector<vector<int>> u(q, vector<int>(3));
    for (int i = 0; i < q; i++) cin >> u[i][0] >> u[i][1] >> u[i][2];
    Solution a;
    vector<int> ans = a.updateQuery(n, q, u);  //<<endl;
    for (auto j : ans) {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}
// } Driver Code Ends
