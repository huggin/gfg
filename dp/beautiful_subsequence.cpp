//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  int longest_Subsequence(int a[], int n) {
    // Complete the function
    sort(a, a + n);
    vector<int> dp(n, 1);
    int ans = 1;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (a[i] % a[j] == 0 || a[j] % a[i] == 0) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      ans = max(ans, dp[i]);
    }
    return ans == 1 ? -1 : ans;
  }
};

//{ Driver Code Starts.
int main() {
  // code

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    Solution ob;
    cout << ob.longest_Subsequence(a, n) << endl;
  }

  return 0;
}
// } Driver Code Ends
