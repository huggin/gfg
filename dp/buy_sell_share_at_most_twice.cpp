//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

int maxProfit(vector<int> &price) {
  // Write your code here..
  int n = price.size();

  vector<int> dp(n), dp2(n);
  int mi = price[0];
  for (int i = 1; i < n; ++i) {
    if (price[i] >= mi) {
      dp[i] = max(dp[i - 1], price[i] - mi);
    } else {
      dp[i] = dp[i - 1];
      mi = price[i];
    }
  }
  int ma = price[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    if (price[i] <= ma) {
      dp2[i] = max(dp2[i + 1], ma - price[i]);
    } else {
      dp2[i] = dp2[i + 1];
      ma = price[i];
    }
  }

  int ans = 0;
  for (int i = 1; i < n; ++i) {
    ans = max(ans, dp[i - 1] + dp2[i]);
  }
  return ans;
}

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> price(n);
    for (int i = 0; i < n; i++)
      cin >> price[i];
    cout << maxProfit(price) << endl;
  }
}

// } Driver Code Ends
