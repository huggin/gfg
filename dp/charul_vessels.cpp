//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

bool vessel(int a[], int n, int k);

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int a[n + 1];

    for (int i = 0; i < n; i++)
      cin >> a[i];

    if (vessel(a, n, k)) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
  }
  return 0;
}

// } Driver Code Ends

bool vessel(int a[], int n, int k) {
  // Complete the function
  vector<int> dp(k + 1);
  dp[0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= k; ++j) {
      if (j - a[i] >= 0)
        dp[j] |= dp[j - a[i]];
    }
  }
  return dp[k];
}
