//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  int dp[1001];
  int n;
  int solve(int w, int val[], int wt[]) {
    if (w <= 0) return 0;
    if (dp[w] != -1) return dp[w];
    int& ans = (dp[w] = 0);
    for (int i = 0; i < n; ++i) {
      if (w >= wt[i]) {
        ans = max(ans, solve(w - wt[i], val, wt) + val[i]);
      }
    }
    return ans;
  }

 public:
  int knapSack(int N, int W, int val[], int wt[]) {
    // code here
    memset(dp, -1, sizeof(dp));
    n = N;
    return solve(W, val, wt);
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N, W;
    cin >> N >> W;
    int val[N], wt[N];
    for (int i = 0; i < N; i++) cin >> val[i];
    for (int i = 0; i < N; i++) cin >> wt[i];

    Solution ob;
    cout << ob.knapSack(N, W, val, wt) << endl;
  }
  return 0;
}
// } Driver Code Ends
