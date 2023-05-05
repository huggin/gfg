//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  int minCost(vector<vector<int>> &costs) {
    // write your code here
    int n = costs.size();
    int k = costs[0].size();
    if (n > k && k == 1)
      return -1;

    vector<vector<int>> dp(n, vector<int>(k));
    for (int i = 0; i < k; ++i) {
      dp[0][i] = costs[0][i];
    }
    for (int i = 1; i < n; ++i) {
      int j1 =
          min_element(dp[i - 1].begin(), dp[i - 1].end()) - dp[i - 1].begin();

      for (int j = 0; j < k; ++j) {
        if (j != j1) {
          dp[i][j] = dp[i - 1][j1] + costs[i][j];
        } else {
          int m2 = INT_MAX;
          for (int j2 = 0; j2 < k; ++j2) {
            if (j2 == j || j2 == j1)
              continue;
            m2 = min(m2, dp[i - 1][j2]);
          }
          dp[i][j] = m2 + costs[i][j];
        }
      }
    }

    return *min_element(dp[n - 1].begin(), dp[n - 1].end());
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> costs(n, vector<int>(k));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < k; j++)
        cin >> costs[i][j];
    }
    Solution obj;
    cout << obj.minCost(costs) << endl;
  }
}
// } Driver Code Ends
