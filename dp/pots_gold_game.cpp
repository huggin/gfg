//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  int dp[500][500];
  int solve(vector<int> &a, int i, int j) {
    if (i > j)
      return 0;
    if (dp[i][j] != -1)
      return dp[i][j];
    int &ans = dp[i][j];
    ans = max(a[i] - solve(a, i + 1, j), a[j] - solve(a, i, j - 1));
    return ans;
  }

public:
  int maxCoins(vector<int> &A, int n) {
    // Write your code here
    memset(dp, -1, sizeof(dp));
    int ans = solve(A, 0, n - 1);
    return (accumulate(A.begin(), A.end(), 0) + ans) / 2;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }
    Solution ob;
    cout << ob.maxCoins(A, N) << "\n";
  }
  return 0;
}

// } Driver Code Ends
