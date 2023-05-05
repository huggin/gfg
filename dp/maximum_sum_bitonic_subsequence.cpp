//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int maxSumBS(int arr[], int n);

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];

    cout << maxSumBS(a, n) << endl;
  }
}
// } Driver Code Ends

int maxSumBS(int arr[], int n) {
  vector<int> dp(n);
  for (int i = 0; i < n; ++i) {
    dp[i] = arr[i];
    for (int j = 0; j < i; ++j) {
      if (arr[j] < arr[i]) {
        dp[i] = max(dp[i], dp[j] + arr[i]);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (arr[j] > arr[i]) {
        dp[i] = max(dp[i], dp[j] + arr[i]);
      }
    }
  }
  return *max_element(dp.begin(), dp.end());
}
