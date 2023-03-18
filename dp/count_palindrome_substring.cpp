//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int CountPS(char S[], int N);

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    char S[N + 1];
    cin >> S;
    cout << CountPS(S, N) << endl;
  }
  return 0;
}

// } Driver Code Ends

int CountPS(char S[], int N) {
  // code here
  int dp[501][501] = {0};
  for (int i = 0; i < N; ++i) {
    dp[i][i] = 1;
  }
  int ans = 0;
  for (int i = 1; i < N; ++i) {
    if (S[i - 1] == S[i]) {
      dp[i - 1][i] = 1;
      ans++;
    }
  }
  for (int i = 2; i < N; ++i) {
    // if (i == 4) cout << "haha";
    for (int j = 0; j + i < N; ++j) {
      if (S[j] == S[j + i] && dp[j + 1][j + i - 1] == 1) {
        // cout << j << ' ' << j + i << endl;
        dp[j][j + i] = 1;
        ++ans;
      }
    }
  }
  return ans;
}
