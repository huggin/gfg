//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

long long int maxSumWithK(long long int a[], long long int n, long long int k);

// Driver code
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k, i;
    cin >> n;
    long long int a[n];
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    cin >> k;
    cout << maxSumWithK(a, n, k) << endl;
  }
  return 0;
}

// } Driver Code Ends

long long int maxSumWithK(long long int a[], long long int n, long long int k) {
  vector<long long> maxSum(n);
  maxSum[0] = a[0];
  for (int i = 1; i < n; ++i) {
    maxSum[i] = max(a[i], a[i] + maxSum[i - 1]);
  }
  long long t = 0;
  for (int i = 0; i < k; ++i) {
    t += a[i];
  }
  long long ans = t;
  for (int i = k; i < n; ++i) {
    t += a[i] - a[i - k];
    ans = max(ans, t);
    if (t + maxSum[i - k] > ans) {
      ans = t + maxSum[i - k];
    }
  }
  return ans;
}
