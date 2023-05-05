//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  int minSum(int a[], int n) {
    // Write your code here
    if (n < 3)
      return 0;
    vector<int> dp(n);
    dp[0] = a[0];
    dp[1] = a[1];
    dp[2] = a[2];
    for (int i = 3; i < n; ++i) {
      dp[i] = min({dp[i - 1], dp[i - 2], dp[i - 3]}) + a[i];
    }
    return min({dp[n - 1], dp[n - 2], dp[n - 3]});
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n + 5];
    for (int i = 0; i < n; i++)
      cin >> a[i];
    Solution ob;
    cout << ob.minSum(a, n) << endl;
  }
  return 0;
}
// } Driver Code Ends
