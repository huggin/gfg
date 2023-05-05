//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  // Function to return maximum sum subarray by removing at most one element.
  int maxSumSubarray(int A[], int n) {
    // Your code here
    vector<int> dp(n + 1), dp2(n + 1);
    int ans = A[0];
    dp[0] = A[0];
    for (int i = 1; i < n; ++i) {
      dp[i] = max(A[i], dp[i - 1] + A[i]);
      // cout << dp[i] << endl;
      ans = max(dp[i], ans);
    }
    // cout << endl;
    dp2[n - 1] = A[n - 1];
    // cout << dp2[n-1] << endl;
    for (int i = n - 2; i >= 0; --i) {
      dp2[i] = max(A[i], dp2[i + 1] + A[i]);
      // cout << dp2[i] << endl;
      ans = max(dp2[i], ans);
    }
    for (int i = 1; i < n - 1; ++i) {
      ans = max(ans, dp[i - 1] + dp2[i + 1]);
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  // your code goes here

  // taking total testcases
  int t;
  cin >> t;
  while (t--) {
    // taking total elements
    int n;
    cin >> n;
    int a[n];

    // inserting elements in the array
    for (int i = 0; i < n; i++)
      cin >> a[i];

    // calling method maxSumSubarray()
    Solution obj;
    cout << obj.maxSumSubarray(a, n) << endl;
  }
}

// } Driver Code Ends
