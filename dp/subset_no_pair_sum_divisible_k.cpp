//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int subsetPairNotDivisibleByK(int arr[], int N, int K);

//  Driver code to test above methods
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int a[n + 5];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    cout << subsetPairNotDivisibleByK(a, n, k) << "\n";
  }
  return 0;
}
// } Driver Code Ends

int subsetPairNotDivisibleByK(int arr[], int N, int K) {
  vector<int> dp(K);
  for (int i = 0; i < N; ++i) {
    dp[arr[i] % K]++;
  }
  int ans = 0;
  if (dp[0])
    ans++;
  for (int i = 1; i <= K / 2; ++i) {
    if (i == K - i) {
      if (dp[i])
        ++ans;
    } else {
      ans += max(dp[i], dp[K - i]);
    }
  }
  return ans;
}
