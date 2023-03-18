//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool validSequence(int arr[], int n, int M);

int main() {
  int t, n, M;
  cin >> t;
  while (t--) {
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> M;

    if (validSequence(arr, n, M))
      cout << 1 << endl;
    else
      cout << 0 << endl;
  }
  return 0;
}

// } Driver Code Ends

vector<vector<int>> dp;
int m;
int n;

int solve(int arr[], int k, int r) {
  if (k == n) {
    if (r == 0) return 1;
    return 0;
  }
  if (dp[k][r] != -1) return dp[k][r];
  int& ans = dp[k][r];
  ans = 0;
  ans = solve(arr, k + 1, (r + arr[k]) % m) ||
        solve(arr, k + 1, (r + m - arr[k]) % m);
  return ans;
}

bool validSequence(int arr[], int N, int M) {
  // Complete the function
  n = N;
  for (int i = 0; i < n; ++i) {
    arr[i] %= M;
    // cout << arr[i] << ' ';
  }
  // cout << endl;
  dp.assign(n, vector<int>(M, -1));
  m = M;
  return solve(arr, 1, arr[0]);
}
