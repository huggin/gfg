//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
public:
  long long int findMaxValue(long long int arr[], int n) {
    // code here
    vector<long long> dp(n), dp2(n);
    long long mi = arr[0];
    dp[0] = INT_MIN;
    for (int i = 1; i < n; ++i) {
      dp[i] = max(dp[i - 1], arr[i] - mi);
      mi = min(mi, arr[i]);
    }
    dp2[n - 1] = INT_MIN;
    long long ma = arr[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      dp2[i] = max(dp2[i + 1], ma - arr[i]);
      ma = max(ma, arr[i]);
    }
    long long ans = INT_MIN;
    for (int i = 1; i < n - 2; ++i) {
      ans = max(ans, dp[i] + dp2[i + 1]);
    }
    if (ans == INT_MIN)
      return -1;
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long i, arr[n];
    for (i = 0; i < n; i++) {
      cin >> arr[i];
    }
    Solution ob;
    cout << ob.findMaxValue(arr, n) << endl;
  }
  return (0);
}

// } Driver Code Ends
