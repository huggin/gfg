//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int countPalinInRange(int n, string A, int q1, int q2);
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q1, q2;
    cin >> q1 >> q2;
    cout << countPalinInRange(n, s, q1, q2) << '\n';
  }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends

int countPalinInRange(int n, string A, int q1, int q2) {
  // your code here
  if (q1 > q2)
    swap(q1, q2);
  // cout << A.substr(q1, q2-q1+1) << endl;
  vector<vector<int>> dp(n, vector<int>(n));
  int ans = 0;
  for (int i = q1; i <= q2; ++i) {
    dp[i][i] = 1;
    ++ans;
  }
  for (int i = q1 + 1; i <= q2; ++i) {
    if (A[i] == A[i - 1]) {
      dp[i - 1][i] = 1;
      ++ans;
    }
  }
  for (int k = 2; k < q2 - q1 + 1; ++k) {
    for (int i = q1; i + k <= q2; ++i) {
      int j = i + k;
      if (A[i] == A[j] && dp[i + 1][j - 1] == 1) {
        dp[i][j] = 1;
        ++ans;
      }
    }
  }
  return ans;
}
