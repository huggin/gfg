//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  int dp[1001][1001];
  int dp2[1001][1001];
  int* a;
  int solve(int i, int j) {
    if (i == j) {
      return a[i];
    }
    if (dp[i][j] != -1) return dp[i][j];
    int& ans = dp[i][j];
    ans = max(a[i] - solve2(i + 1, j), a[j] - solve2(i, j - 1));
    return ans;
  }

  int solve2(int i, int j) {
    if (i == j) return a[i];
    if (dp2[i][j] != -1) return dp2[i][j];
    int& ans = dp2[i][j];
    ans = max(a[i] - solve(i + 1, j), a[j] - solve(i, j - 1));

    return ans;
  }

 public:
  bool is1winner(int N, int arr[]) {
    // code here
    memset(dp, -1, sizeof(dp));
    memset(dp2, -1, sizeof(dp2));
    a = arr;
    int ans = solve(0, N - 1);
    if (ans > 0) return 1;
    return 0;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N, X;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++) {
      cin >> arr[i];
    }

    Solution ob;
    cout << ob.is1winner(N, arr) << endl;
  }
  return 0;
}

// } Driver Code Ends
