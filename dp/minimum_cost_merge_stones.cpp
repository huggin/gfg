//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  vector<int> sum;
  int n, K;
  vector<vector<int>> dp;

  int solve(int i, int j) {
    if (j - i < K - 1) {
      return 0;
    }

    if (dp[i][j] != -1)
      return dp[i][j];
    int &ans = dp[i][j];
    ans = INT_MAX;
    for (int k = i; k < j; k += K - 1) {
      ans = min(ans, solve(i, k) + solve(k + 1, j));
    }
    if ((j - i) % (K - 1) == 0) {
      ans += sum[j + 1] - sum[i];
    }
    return ans;
  }

public:
  int mergeStones(vector<int> &stones, int N, int K) {
    // code here
    if ((N - 1) % (K - 1) != 0)
      return -1;

    sum.assign(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
      sum[i] = sum[i - 1] + stones[i - 1];
    }
    n = N;
    this->K = K;
    dp.assign(N, vector<int>(N, -1));
    return solve(0, N - 1);
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N, K;
    cin >> N >> K;

    vector<int> stones(N);

    for (int i = 0; i < N; i++) {
      cin >> stones[i];
    }

    Solution obj;

    cout << obj.mergeStones(stones, N, K) << endl;
  }
  return 0;
}
// } Driver Code Ends
