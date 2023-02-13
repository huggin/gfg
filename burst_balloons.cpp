//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  int dp[301][301];
  vector<int> a;
  int n;

  int solve(int i, int j) {
    if (i > j) return 0;
    if (i == j) return dp[i][j] = a[i - 1] * a[i] * a[j + 1];
    if (dp[i][j] != -1) return dp[i][j];
    for (int k = i; k <= j; ++k) {
      dp[i][j] = max(dp[i][j], a[i - 1] * a[k] * a[j + 1] + solve(i, k - 1) +
                                   solve(k + 1, j));
    }
    return dp[i][j];
  }

 public:
  int maxCoins(int N, vector<int> &arr) {
    // code here
    memset(dp, -1, sizeof(dp));
    a.assign(N + 2, 1);
    for (int i = 0; i < arr.size(); ++i) {
      a[i + 1] = arr[i];
    }
    n = N + 2;
    return solve(1, N);
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    Solution obj;
    cout << obj.maxCoins(N, arr) << endl;
  }
  return 0;
}
// } Driver Code Ends
